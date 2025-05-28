using System;
using LitJson;
using Robot;
using Unity.XR.PICO.TOBSupport;
using UnityEngine;

public partial class UICameraCtrl
{
    private void OnNetReceive(string functionName, string value)
    {
        if (!gameObject.activeSelf)
        {
            return;
        }

        if (functionName == "CameraRecord")
        {
            bool record = false;

            int videoWidth = 1024;
            int videoHeight = 768 / 2;
            int videoFps = 30;
            int bitrate = 10 * 1024 * 1024;
            int captureRenderMode = (int)PXRCaptureRenderMode.PXRCapture_RenderMode_3D;

            try
            {
                Debug.Log("value:" + value);
                value = value.Replace("\\", "");
                JsonData json = JsonMapper.ToObject(value);
                int.TryParse(json["on"].ToString(), out var on);
                record = on == 1;
                if (record)
                {
                    int.TryParse(json["videoFps"].ToString(), out videoFps);
                    int.TryParse(json["videoWidth"].ToString(), out videoWidth);
                    int.TryParse(json["videoHeight"].ToString(), out videoHeight);
                    int.TryParse(json["bitrate"].ToString(), out bitrate);
                    if (json.ContainsKey("captureRenderMode"))
                    {
                        int.TryParse(json["captureRenderMode"].ToString(), out captureRenderMode);
                    }
                }
            }
            catch (Exception e)
            {
                Debug.LogError(e);
            }


            if (RecordBtn.On != record)
            {
                if (record)
                {
                    StartRecord(videoWidth, videoHeight, videoFps, bitrate, false);
                }
                else
                {
                    StopRecord();
                }
            }
        }
        else if (functionName == "GetCameraParam")
        {
            Debug.Log("value:" + value);
            value = value.Replace("\\", "");
            JsonData json = JsonMapper.ToObject(value);
            int width = 2048;
            int height = 1536;
            if (json.ContainsKey("width"))
            {
                width = int.Parse(json["width"].ToString());
            }

            if (json.ContainsKey("height"))
            {
                height = int.Parse(json["height"].ToString());
            }

            string cameraExtrinsics = Utils.GetCameraExtrinsicsStrE();
            string cameraIntrinsics = Utils.GetCameraIntrinsicsStrE(width, height);
            JsonData cameraParam = new JsonData();
            cameraParam["resolution"] = string.Format("{0}x{1}", width, height);
            cameraParam["cameraExtrinsics"] = cameraExtrinsics;
            cameraParam["cameraIntrinsics"] = cameraIntrinsics;
            TcpHandler.SendFunctionValue("GetCameraParam", cameraParam.ToJson());
        }
        else if (functionName == "ResponsePcCamera")
        {
            Debug.Log("value:" + value);
            value = value.Replace("\\", "");
            JsonData json = JsonMapper.ToObject(value);

            int.TryParse(json["res"].ToString(), out var res);

            if (res == 0)
            {
                JsonData cameraList = json["CameraList"];
                CameraRequestDialog.SetCameraList(cameraList);

                CameraRequestDialog.Show(
                    () =>
                    {
                        Debug.Log(CameraRequestDialog.ResolutionWidth + " " + CameraRequestDialog.ResolutionHeight +
                                  " " +
                                  CameraRequestDialog.Fps + " " + CameraRequestDialog.Bitrate);

                        int port = Utils.GetAvailablePort();
                        RemoteCameraWindowObj.SetActive(true);
                        RemoteCameraWindowObj.GetComponent<RemoteCameraWindow>()
                            .StartListen(CameraRequestDialog.ResolutionWidth, CameraRequestDialog.ResolutionHeight,
                                CameraRequestDialog.Fps, CameraRequestDialog.Bitrate, port);
                    },
                    null);
            }
            else
            {
                Debug.LogWarning("ResponsePcCamera fail res+" + res);
            }
        }
        else if (functionName == "RequestVRCamera")
        {
            Toast.Show("Receive VR camera Request");
            //The VR camera image acquisition is only effective on the B-end device of Pico4U.
            if (!Utils.IsPico4U())
            {
                Debug.LogWarning("Please use B-end pico4U devices and apply for camera permissions.");
                return;
            }

            value = value.Replace("\\", "");
            JsonData json = JsonMapper.ToObject(value);

            int.TryParse(json["on"].ToString(), out var on);
            bool open = on == 1;
            if (open)
            {
                //  string ip = json["ip"].ToString();
                int.TryParse(json["port"].ToString(), out var port);
                int.TryParse(json["width"].ToString(), out var width);
                int.TryParse(json["height"].ToString(), out var height);
                int.TryParse(json["fps"].ToString(), out var fps);
                int.TryParse(json["bitrate"].ToString(), out var bitrate);
                int.TryParse(json["captureRenderMode"].ToString(), out var captureRenderMode);


                string ip = TcpHandler.GetTargetIP;
                _recordTrackingData = false;
                CameraHandle.StartCameraPreview(width, height, fps, bitrate, 0, captureRenderMode,
                    () => { CameraHandle.StartSendImage(ip, port); });
            }
            else
            {
                StopSendImage();
                JsonData cameraParam = new JsonData();
                TcpHandler.SendFunctionValue("VRCameraClose", cameraParam.ToJson());
            }
        }
    }
}