using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
public class Restart : MonoBehaviour
{
    public void re_load_scene ()
    {
        SceneManager.LoadScene("load");
    }
}
