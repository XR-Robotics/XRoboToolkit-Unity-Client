using Codice.Client.Common.FsNodeReaders;
using Codice.LogWrapper;
using PlasticPipe.Client;

namespace Unity.PlasticSCM.Editor
{
    internal static class PlasticShutdown
    {
        internal static void Shutdown()
        {
            mLog.Debug("Shutdown");

            WorkspaceFsNodeReaderCachesCleaner.Shutdown();

            PlasticPlugin.Shutdown();
            PlasticApp.Dispose();

            ClientConnectionPool.Shutdown();
        }

        static readonly ILog mLog = PlasticApp.GetLogger("PlasticShutdown");
    }
}
