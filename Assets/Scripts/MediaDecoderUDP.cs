﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MediaDecoderUDP
{
    private static AndroidJavaObject _javaObj = null;

    private static AndroidJavaObject GetJavaObject()
    {
        if (_javaObj == null)
        {
            _javaObj = new AndroidJavaObject("com.picovr.robotassistantlib.MediaDecoderUDP");
        }

        return _javaObj;
    }

    public static void initialize(int unityTextureId, int width, int height)
    {
        GetJavaObject().Call("initialize", unityTextureId, width, height);
    }

    public static void startServer(int port, bool record)
    {
        GetJavaObject().Call("startServer", port, record);
    }

    public static bool isUpdateFrame()
    {
        return GetJavaObject().Call<bool>("isUpdateFrame");
    }

    public static void updateTexture()
    {
        GetJavaObject().Call("updateTexture");
    }

    public static void release()
    {
        GetJavaObject().Call("release");
    }
}