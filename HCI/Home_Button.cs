//----------------------------------------------
//            NGUI: Next-Gen UI kit
// Copyright ?2011-2013 Tasharen Entertainment
//----------------------------------------------

using UnityEngine;
using System.Collections;

public class Home_Button : MonoBehaviour
{	
	public GameObject Home;
	public void OnClick () { 
		Application.LoadLevel ("Main");
		NGUITools.SetActive (Home, false);
	}
}