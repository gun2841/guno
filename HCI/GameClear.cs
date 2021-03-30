using UnityEngine;
using System.Collections;

public class GameClear : MonoBehaviour {
	
	void OnTriggerEnter(Collider _col)
	{
		if(_col.transform.name == "FPSController")
		{
			Application.LoadLevel("GameClear");	
		}
	}
}
