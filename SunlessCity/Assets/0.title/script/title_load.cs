using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class title_load : MonoBehaviour {
    public void temp_load
        () {
        LoadingScene.LoadScene("temp");
    }
    public void sandbox_load() {
        LoadingScene.LoadScene("sandbox");
    }
}

