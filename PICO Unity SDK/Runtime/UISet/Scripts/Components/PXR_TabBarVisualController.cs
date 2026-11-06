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
using TMPro;
using UnityEngine.UI;
#if UNITY_EDITOR || DEVELOPMENT_BUILD
namespace ByteDance.PICO.Debugger
{
    public class PXR_TabBarVisualController : MonoBehaviour
    {
        public int messageCount;
        public Sprite sprite;
        public Image image;
        private const float defaultSize = 16f;
        private const int maxCount = 4;
        private const float step = 5f;
        private const int ceiling = 999;
        public RectTransform badge;
        public TextMeshProUGUI text;
        private void OnValidate()
        {
            image.sprite = sprite;
            ChangeMessageCount(messageCount);
        }
        public void ChangeMessageCount(int amount)
        {
            if (amount < 0) return;
            messageCount = amount;
            var count = Mathf.Min(Mathf.Abs(amount).ToString().Length, maxCount);
            badge.sizeDelta = new Vector2(defaultSize + (count - 1) * step, defaultSize);
            text.text = amount > ceiling ? $"{ceiling}+" : $"{amount}";
            badge.gameObject.SetActive(amount > 0);
        }
        public void AddMessage()
        {
            ChangeMessageCount(messageCount + 1);
        }
        public void RemoveMessage()
        {
            ChangeMessageCount(messageCount - 1);
        }
    }
}
#endif