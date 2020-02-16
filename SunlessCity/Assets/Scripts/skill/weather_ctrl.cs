using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class weather_ctrl : MonoBehaviour
{
  public  GameObject[] target_;
    public int r;
    void OnEnable()
    {
        r = Random.Range(0, 4);

        target_[r].SetActive(true);
    }
    void OnDisable()
    {
        target_[r].SetActive(false);
    }
}
