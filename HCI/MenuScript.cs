using UnityEngine;
using System.Collections;

public class MenuScript : MonoBehaviour {

	public void Load_DEasy()
	{
		Application.LoadLevel ("MAP_D-1");
	}
	public void Load_DNormal()
	{
		Application.LoadLevel ("MAP_D-2");
	}
	public void Load_DHard()
	{
		Application.LoadLevel ("MAP_D-3");
	}
	public void Load_FEasy()
	{
		Application.LoadLevel ("MAP_F-1");
	}
	public void Load_FNormal()
	{
		Application.LoadLevel ("MAP_F-2");
	}
	public void Load_FHard()
	{
		Application.LoadLevel ("MAP_F-3");
	}
}
