using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class click_event : MonoBehaviour {
    public AudioSource aud;
    Vector2 mousePos;
    public void tap()
    {
        aud.Play();
    //    click_object.GetComponent<Animation>().Play("start_btn");
    }
    
}
