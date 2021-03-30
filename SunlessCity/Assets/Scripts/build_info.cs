using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class build_info : MonoBehaviour {

    public int index;
    public int width;
    public new string name;
    public string thema;
    public int target;
    public void reset()
    {
        index = 0; width = 0; name = "";
        thema = ""; target = 0;
    }
}
