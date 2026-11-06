#if PICO_MS_SDK

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

namespace ByteDance.PICO.SpatialAdapter
{
    public class RandomPrefabSpawner : MonoBehaviour
    {
        public GameObject prefab;
        public float spawnAreaSize = 10f;
        public float spawnInterval = 1f;

        public int selectingPointer { get; private set; } = ManipulationInputManager.k_Deselected;

        private void Start()
        {
            StartCoroutine(SpawnPrefab());
        }

        public void Update()
        {
        }

        private IEnumerator SpawnPrefab()
        {
            float x = Random.Range(spawnAreaSize, spawnAreaSize);
            float y = Random.Range(spawnAreaSize, spawnAreaSize);
            Vector3 spawnPosition = new Vector3(x, y, x); 
            
            Instantiate(prefab, spawnPosition, Quaternion.identity);

      
            yield return new WaitForSeconds(spawnInterval);
        }

        public void SetSelected(int pointer)
        {
            var isSelected = pointer != ManipulationInputManager.k_Deselected;
            selectingPointer = pointer;

            if (isSelected)
            {
                StartCoroutine(SpawnPrefab());
            }
        }
    }
}
#endif