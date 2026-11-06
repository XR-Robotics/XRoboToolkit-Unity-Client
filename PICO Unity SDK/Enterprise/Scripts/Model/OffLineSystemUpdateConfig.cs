using System;

namespace ByteDance.PICO.Enterprise
{
    public class OffLineSystemUpdateConfig
    {
        // OTA package path
        public String otaFilePath = null;
        // Whether to auto-reboot after upgrade completes
        public Boolean autoReboot = true;
        // Whether to display progress during upgrade
        public Boolean showProgress = false;
        public OffLineSystemUpdateConfig()
        {
        }

        public OffLineSystemUpdateConfig(string otaFilePath, bool autoReboot, bool showProgress)
        {
            this.otaFilePath = otaFilePath;
            this.autoReboot = autoReboot;
            this.showProgress = showProgress;
        }
    }
}