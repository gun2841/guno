using UnityEngine;
using System.Collections;


public enum vinestate{
	Default,
	moved
}
public class movescript : MonoBehaviour {

	
	public vinestate vine;
	public Animator animator;
	public AudioSource someSound;
	
	void Start(){
		vine = vinestate.Default;
	}
	void OnTriggerEnter(Collider coll)
	{
		if (coll.gameObject.name == "FPSController") {
			someSound.Play ();
			if (vine == vinestate.Default) {
				move ();
			}
		}

	}
	void move(){
		vine = vinestate.moved;
		animator.SetTrigger ("move");
		
	}
}
