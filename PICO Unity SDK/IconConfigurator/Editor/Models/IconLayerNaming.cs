namespace ByteDance.PICO.IconConfigurator.Editor
{
    public static class IconLayerNaming
    {
        public static IconLayerKind GetLayerKind(int layerIndex)
        {
            return layerIndex switch
            {
                0 => IconLayerKind.Background,
                1 => IconLayerKind.Foreground1,
                _ => IconLayerKind.Foreground2,
            };
        }

        public static string GetDisplayName(int layerIndex)
        {
            return layerIndex switch
            {
                0 => "Background",
                1 => "Foreground1",
                2 => "Foreground2",
                _ => $"Foreground{layerIndex}",
            };
        }

        public static string GetPngFileName(int layerIndex)
        {
            return layerIndex switch
            {
                0 => "background.png",
                1 => "foreground1.png",
                2 => "foreground2.png",
                _ => $"foreground{layerIndex}.png",
            };
        }

        public static string GetAndroidLayerResourceName(int layerIndex)
        {
            return $"icon_3d_layer_{layerIndex}";
        }

        public static string GetAndroidSdfResourceName(int layerIndex)
        {
            return $"icon_3d_sdf_{layerIndex}";
        }
    }
}
