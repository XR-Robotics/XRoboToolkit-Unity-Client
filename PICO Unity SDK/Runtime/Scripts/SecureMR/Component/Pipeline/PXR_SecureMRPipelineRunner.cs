#if !ENABLE_PICO_OPENXR_SDK
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace ByteDance.PICO.SecureMR
{
    public class PXR_SecureMRPipelineRunner : MonoBehaviour
    {
        public PXR_SecureMRPipelineExecute[] runners;
        // Start is called before the first frame update
        void Start()
        {

        }

        // Update is called once per frame
        void Update()
        {
            foreach (var exec in runners)
            {
                exec.Execute();
            }
        }
    }
}
#endif
