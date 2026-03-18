namespace Unity.PlasticSCM.Editor.Views.IncomingChanges
{
    internal interface IIncomingChangesTab
    {
        bool IsVisible
        {
            get; set;
        }

        void OnEnable();
        void OnDisable();
        void Update();
        void OnGUI();
        void AutoRefresh();
    }
}
