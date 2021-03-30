using UnityEngine;
using System.Collections;

public class TimeTrigger : MonoBehaviour {

	int x;
	public AudioSource someSound;


    void OnTriggerEnter(Collider coll)
    {
		someSound.Play ();
        if (coll.gameObject.name == "FPSController")
        {
			x = Random.Range (0,1);
			if(x == 0)
				Timer.timeRemaining/=2;
			else
				Timer.timeRemaining*=2;
        }

    }
    // Use this for initialization
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }
}
