using UnityEngine;
using System.Collections;

public class Timer : MonoBehaviour {

	public static float timeRemaining = 10;
	public UILabel Remain;
	private int minute;
	private int second;


    void Start()
	{
	}
	void Update () {
		timeRemaining -= Time.deltaTime;
		minute = (int)timeRemaining / 60;
		second = ((int)timeRemaining - minute * 60);
		if (timeRemaining > 0) {
			Remain.text = "[ff0000]"+minute.ToString() +
				" : " + second.ToString()+"[-]";
		}
		else
		{
			Remain.text = "Game Over";
			Application.LoadLevel("GameOver");
		}
	}
}
