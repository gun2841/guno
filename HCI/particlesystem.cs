using UnityEngine;
using System.Collections;

public class particlesystem : MonoBehaviour {

	public ParticleSystem testParticle;

	void OnTriggerEnter(Collision coll)
	{
		if (testParticle)
		if (testParticle.isPlaying == true) {
			testParticle.Stop ();
			testParticle.Clear ();
		} else {
			testParticle.Play ();
		}
	}
}
