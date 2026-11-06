using System;

namespace ByteDance.PICO.IconConfigurator.Editor
{
    public interface IIconAiSplitService
    {
        bool IsRunning { get; }

        void StartGenerate(
            IconLayerConfig sourceLayer,
            string configGuid,
            Action<float> onProgress,
            Action<IconAiSplitResult, string, string> onSuccess,
            Action<string> onError);

        void Cancel();
    }
}
