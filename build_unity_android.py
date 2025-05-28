#!/usr/bin/env python
# -*- coding:utf-8 -*-
import hashlib
import json
import os
import re
import requests
import shutil
import sys
import subprocess
import stat
import time
import zipfile
unityPath = None
productName = None
method = None
outputPath = None
version = None
versionCode = None
tostxt = None

def usage():
    print('')
    print('Usage:')
    print(' export_unity_android.py unityPath productName method')
    print(' e.g.:')
    print(' build_unity_android.py "D:/tools/Unity5.2.3f1/Editor/Unity.exe" "VRLauncher2" "ProjectBuild.BuildForAndroid"')
    print('')
def process_env():
    global signtool, zipalign_exe, pdmRepo, version, versionCode, commitid, signKeyID, signType, apk_build_tag, build_revision, branch, tostxt, apk_build_outputs, apk_output_keys, apk_output_sub, final_output
    signtool = os.environ['HOME'] + '/src/github/smartcm/scm-helpers/.apksigner.jar'
    zipalign_exe = os.environ['HOME'] + "/android-sdk-linux/build-tools/29.0.1/zipalign"

    pdmRepo = "daily-build"
    final_output = 'build/dist/'
    apk_output_keys = "release,debug"
    if os.environ.has_key('pdm_repo'): pdmRepo = os.environ['pdm_repo']
    if os.environ.has_key('versionname'): version = os.environ['versionname']
    if os.environ.has_key('versioncode'): versionCode = os.environ['versioncode']
    if os.environ.has_key('last_u3d_commit'): commitid = os.environ['last_u3d_commit']
    if os.environ.has_key('APK_SIGN_KEYS'): signKeyID = os.environ['APK_SIGN_KEYS']
    if os.environ.has_key('APK_KEY_TYPE'): signType = os.environ['APK_KEY_TYPE']
    if os.environ.has_key('buildTag'): apk_build_tag = os.environ['buildTag']
    if os.environ.has_key('buildRevision'): build_revision = os.environ['buildRevision']
    if os.environ.has_key('GIT_BRANCH_NAME'): branch = os.environ['GIT_BRANCH_NAME']
    if os.environ.has_key('toslinkfile'): tostxt = os.environ['toslinkfile']
    #if os.environ.has_key('APK_BUILD_OUTPUTS'): apk_build_outputs = os.environ['APK_BUILD_OUTPUTS']
    if os.environ.has_key('APK_PUSH_SUBDIR'):apk_output_sub = os.environ['APK_PUSH_SUBDIR']
    if os.environ.has_key('OUTPUT'): final_output = os.environ['OUTPUT']
    if final_output[-1] != '/': final_output = final_output + '/'
    final_output = final_output + methodKey + '/'


def process_args(argv):
    global unityPath, productName, projectPath, method, methodKey, output_list
    if len(sys.argv) < 4:
        usage()
        sys.exit(2)
    unityPath = sys.argv[1]
    productName = sys.argv[2]
    method = sys.argv[3]

    methodKey = method.split('.')[1]
    if methodKey == '':
        print("method parameter error!")
        sys.exit(2)
    projectPath = os.path.split(os.path.realpath(__file__))[0]
    output_list = []

    if unityPath is None or unityPath == '' or productName is None or productName == '':
        print("arguments not satisfied!")
        usage()
        sys.exit(2)

def prebuildUnity():
    os.chdir(projectPath)
    print("Pre compilation preprocessing version number")
    # remove ProjectVersion.txt
    if os.path.exists(projectPath + '/ProjectSettings/ProjectVersion.txt'):
        os.remove(projectPath + '/ProjectSettings/ProjectVersion.txt')
    # unity logo deal
    ProjSettingsbak = projectPath + '/ProjectSettings/ProjectSettings.asset.bak'
    ProjSettings = projectPath + '/ProjectSettings/ProjectSettings.asset'
    if os.path.exists(ProjSettingsbak):
        os.remove(ProjSettingsbak)
    with open(ProjSettings, "r") as f:
        for line in f.readlines():
            with open(ProjSettingsbak, "a") as f2:
                if "m_ShowUnitySplashScreen" in line:
                    f2.write(line.replace(r'm_ShowUnitySplashScreen: 1', r'm_ShowUnitySplashScreen: 0'))
                elif "m_ShowUnitySplashLogo" in line:
                    f2.write(line.replace(r'm_ShowUnitySplashLogo: 1', 'm_ShowUnitySplashLogo: 0'))
                elif "AndroidBundleVersionCode" in line:
                    AndroidBundleVersionCode = ''.join(re.findall(r"AndroidBundleVersionCode: (.+)\n", line, re.M))
                    f2.write(line.replace(r'AndroidBundleVersionCode: ' + str(AndroidBundleVersionCode), 'AndroidBundleVersionCode: ' + versionCode))
                else:
                    f2.write(line)
    os.remove(ProjSettings)
    os.rename(ProjSettingsbak, ProjSettings)
def build_UnityAndroid():
    if os.path.exists(projectPath+'/build'):
        os.chmod(projectPath+'/build', stat.S_IWRITE)
        shutil.rmtree(projectPath+'/build')
    if version and versionCode:
        build_cmd = [unityPath, '-batchmode', '-nographics', '-buildTarget', 'android',
                     '-projectPath', projectPath,
                     '-executeMethod', method,
                     'productName=%s' % productName,
                     'outputPath=%s' % final_output + 'origin/' + productName + '.apk',
                     'version=%s' % version,
                     'versionCode=%s' % versionCode,
                     '-logFile', 'build.log', '-quit', '-upmNoDefaultPackages']
    else:
        build_cmd = [unityPath, '-batchmode', '-nographics', '-buildTarget', 'android',
                     '-projectPath', projectPath,
                     '-executeMethod', method,
                     'productName=%s' % productName,
                     'outputPath=%s' % final_output + 'origin/' + productName + '.apk',
                     '-logFile', 'build.log', '-quit', '-upmNoDefaultPackages']
    ret = subprocess.check_call(build_cmd)
    if ret != 0:
        print("unity build failed!")
        sys.exit(2)

def copy_apk_to_output():
    buildtime = time.strftime("%Y%m%d%H%M%S", time.localtime())
    os.chdir(projectPath)

    #删除build/dist/origin下的apk
    apk_path_files = os.listdir(final_output + 'origin/')
    for file in apk_path_files:
        #build/dist/origin下的symbols加到output_list
        if 'symbols' in file:
            output_list.append(final_output + 'origin/' + file)
        #给apk换名字
        for i in apk_output_keys.split(','):
            for j in apk_output_sub.split(','):
                if file.endswith(".apk") and i in file and j in file:
                    apk_file_name = productName + '_' + methodKey + '_' + commitid + '_' + version + '_' + buildtime + '_' + j + '-' + i
                    shutil.copy(final_output + 'origin/' + file, final_output + 'origin/' + apk_file_name + '.apk')
                    if not os.path.exists(final_output + 'origin/' + apk_file_name + '.apk'):
                        print("拷贝apk失败, 尝试再次拷贝..............")
                        shutil.copy(final_output + 'origin/' + file, final_output + 'origin/' + apk_file_name + '.apk')
                    if not os.path.exists(final_output + 'origin/' + apk_file_name + '.apk'):
                        print("再次拷贝失败, 退出编译..............")
                        sys.exit(2)
                    os.remove(final_output + 'origin/' + file)

#after zipalign apk in the "app"
def zipalignApp():
    os.chdir(projectPath)
    os.makedirs(final_output + '/app')
    list_origin = os.listdir(final_output + '/origin')
    for i in list_origin:
        if i.endswith("apk"):
            cmd_i = zipalign_exe + ' -p -f -v ' + ' 4 ' + final_output + 'origin/' + i + " " + final_output + 'app/' + i
            os.system(cmd_i)
            os.remove(final_output + 'origin/' + i)
            output_list.append(final_output + 'app/' + i)

def do_sign_apk():
    #final_output = 'build/dist'
    app_list = os.listdir(final_output + '/app')
    app_list_path = projectPath + '/' + final_output + '/app'
    for j in app_list:
        for i in signKeyID.split(','):
            if i:
                sign_path = projectPath + '/' + final_output + '/' + i
                if not os.path.exists(sign_path):
                    os.makedirs(sign_path)
                #sign_cmd = ['python', '-u', signtool_script, '-k', '%s' % i, '-i', app_list_path + '/' + j, '-o' , sign_path + '/' + j]
                signCom = '/mnt/ota-base/.code/jenkins/sign-apk/sign-apk-' + i + '/' + signType
                sign_cmd = 'java -jar ' + signtool + ' sign  --key ' + signCom + '.pk8 ' + '--cert ' + signCom + '.x509.pem ' + '--out ' + sign_path + '/' + j.replace('.apk','_' + i +'.apk') + ' ' + app_list_path + '/' + j
                print(str(sign_cmd))
                ret = subprocess.check_call(sign_cmd, shell=True)
                if ret != 0:
                    print("-- buildUnityAndroid failed")
                output_list.append(final_output + '/' + i + '/' + j.replace('.apk','_' + i +'.apk'))


def upload_tos():
    global tos_links
    tos_links = []
    tos_objects = {}
    tos_object = {}
    #tos_tools = 'D:/tools/tosutil.exe'
    os.chdir(projectPath)
    apk_build_time = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
    print("output_list:" + str(output_list))
    for apk_file in output_list:
        #app/AppManager/1.3.1_100301001-20220507/cndebug/AppManager_3331330208c57a1f2bfb919a960ff9bcb3bfe8f7_1651936020.apk
        tos_object = {}
        apk_name = apk_file.split('/')[-1]
        tos_key = methodKey + '/' + apk_file.split('/')[-2]
        tos_prefix = "app/" + productName + "/" + build_revision + "/"
        tos_file = "tos://pico-cm-artifact/" + tos_prefix + tos_key + "/" + apk_name
        tos_object["size"] = os.stat(apk_file).st_size
        tos_object["createTime"] = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
        tos_object["digest"] = hashlib.md5(open(apk_file, 'rb').read()).hexdigest()
        tos_object["tosKey"] = tos_prefix + tos_key + "/" + apk_name
        tos_object["name"] = str(apk_name)
        tos_object["uploaded"] = 1
        tos_objects[str(apk_name)] = tos_object
        cmd = 'tosutil cp ' + apk_file + ' ' + tos_file
        print("tos upload :" + apk_file + " " + tos_file)
        ret = subprocess.check_call(cmd, shell=True)
        if ret == 0:
            tos_links.append(tos_file)
        else:
            sys.exit(2)
    tos_obj_json = json.dumps(tos_objects)
    tos_url = "http://pico-pdm-be.bytedance.net/api/v1/buildEntity"
    headers = {"Content-Type":"application/json","accept":"application/json"}
    tos_data_str = '{ "product": "' + productName + '", "deleteFile": false, "project": "PUI", "repo":"' + pdmRepo + '", "uploaded": 1, "version":"' + \
                   str(version) + '", "branch": "' + branch + '", "buildRevision": "' + str(build_revision) + '", "buildTag": "' + \
                   apk_build_tag + '", "buildTime": "' + apk_build_time + '", "builder": "cmbuild", "files":' + tos_obj_json + '}'
    print('-'*20)
    print(tos_data_str)
    print('-'*20)
    r = requests.post(tos_url , headers=headers, data=tos_data_str)
    print(r.text)
    if r.status_code != 200:
        r = requests.put(tos_url , headers=headers, data=tos_data_str)
    if r.status_code != 200:
        print("upload pdm file FAILED!")

    if tostxt:
        f = open("toslinks.txt","w")
        cut_str = ','
        f.write(cut_str.join(tos_links))
        f.close()
        cmd = 'tosutil cp toslinks.txt ' + tostxt
        ret = subprocess.check_call(cmd, shell=True)
        if ret != 0:
            print("TOS upload txt file FAILED!")
            sys.exit(2)

#压缩
def zip_dir(dirname,zipfilename):
    filelist = []
    zf = zipfile.ZipFile(zipfilename, "w", zipfile.zlib.DEFLATED)

    if os.path.isfile(dirname):
        filelist.append(dirname)
    else :
        for root, dirs, files in os.walk(dirname):
            for name in files:
                filelist.append(os.path.join(root, name))
    for tar in filelist:
        arcname = tar[len(dirname):]
        zf.write(tar,arcname)
    zf.close()

def main(argv):
    process_args(argv)
    process_env()
    prebuildUnity()
    build_UnityAndroid()
    copy_apk_to_output()
    zipalignApp()
    do_sign_apk()
    upload_tos()
if __name__=="__main__":
    main(sys.argv)
    sys.exit(0)
