using System;
using Codice.Client.Common;
using Codice.CM.Common;
using Codice.LogWrapper;
using PlasticGui;
using PlasticGui.WorkspaceWindow.Home;
using Unity.PlasticSCM.Editor.Configuration.CloudEdition.Welcome;
using Unity.PlasticSCM.Editor.WebApi;
using UnityEngine;

namespace Unity.PlasticSCM.Editor.Configuration
{
    internal static class AutoConfig
    {
        internal static TokenExchangeResponse PlasticCredentials(
            string unityAccessToken,
            string serverName)
        {
            SetupUnityEditionToken.CreateCloudEditionTokenIfNeeded();

            var startTick = Environment.TickCount;

            var tokenExchangeResponse = WebRestApiClient.PlasticScm.TokenExchange(unityAccessToken);

            mLog.DebugFormat("TokenExchange time {0} ms", Environment.TickCount - startTick);

            if (tokenExchangeResponse == null)
            {
                var warning = PlasticLocalization.GetString(PlasticLocalization.Name.TokenExchangeResponseNull);
                mLog.Warn(warning);
                Debug.LogWarning(warning);
                return null;
            }

            if (tokenExchangeResponse.Error != null)
            {
                var warning = string.Format(
                    PlasticLocalization.GetString(PlasticLocalization.Name.TokenExchangeResponseError),
                    tokenExchangeResponse.Error.Message, tokenExchangeResponse.Error.ErrorCode);
                mLog.ErrorFormat(warning);
                Debug.LogWarning(warning);
                return tokenExchangeResponse;
            }

            if (string.IsNullOrEmpty(tokenExchangeResponse.AccessToken))
            {
                var warning = string.Format(
                    PlasticLocalization.GetString(PlasticLocalization.Name.TokenExchangeAccessEmpty), 
                    tokenExchangeResponse.User);
                mLog.InfoFormat(warning);
                Debug.LogWarning(warning);
                return tokenExchangeResponse;
            }
            
            // This creates the client.conf if needed but doesn't overwrite it if it exists already,
            // and it also updates the profiles.conf and tokens.conf with the new AccessToken
            UserAccounts.SaveAccount(
                serverName,
                SEIDWorkingMode.SSOWorkingMode, // Hub sign-in working mode
                tokenExchangeResponse.User,
                tokenExchangeResponse.AccessToken,
                null,
                null,
                null);

            CloudEditionWelcomeWindow.SaveDefaultCloudServer(
                serverName,
                tokenExchangeResponse.User);

            return tokenExchangeResponse;
        }

        static readonly ILog mLog = PlasticApp.GetLogger("AutoConfig");
    }
}

