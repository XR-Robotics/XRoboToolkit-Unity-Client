/*******************************************************************************
Copyright © 2015-2022 PICO Technology Co., Ltd.All rights reserved.  

NOTICE：All information contained herein is, and remains the property of 
PICO Technology Co., Ltd. The intellectual and technical concepts 
contained herein are proprietary to PICO Technology Co., Ltd. and may be 
covered by patents, patents in process, and are protected by trade secret or 
copyright law. Dissemination of this information or reproduction of this 
material is strictly forbidden unless prior written permission is obtained from
PICO Technology Co., Ltd. 
*******************************************************************************/
using UnityEngine;
using UnityEngine.UI;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
[RequireComponent(typeof(Slider))]
public class PXR_SliderSegmentController : PXR_UIInputHandler
{

    private Slider slider;
    public RectTransform segmentArea;
    public RectTransform segment;
    private const int dotSize = 6;
    public int padding;

    void Awake()
    {
        slider = GetComponent<Slider>();
    }
    void Start()
    {
        if (slider.wholeNumbers)
        {
            int amout = (int)(slider.maxValue - slider.minValue);
            for (var i = 0; i < amout; i++)
            {
                Instantiate(segment.gameObject, segmentArea);
                if (segmentArea.transform.TryGetComponent(out HorizontalLayoutGroup group))
                {
                    group.padding.right = dotSize - 1 * ((int)segmentArea.rect.width / amout);
                }
            }
        }
    }
}
}
#endif