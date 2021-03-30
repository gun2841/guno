using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class shop_top_text : MonoBehaviour {
    public Text targetTXT;
    public string[] str;
	public void change_text(int idx)
    {
        targetTXT.text = str[idx];
    }
}
