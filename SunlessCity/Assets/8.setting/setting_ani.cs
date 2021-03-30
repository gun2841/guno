using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class setting_ani : MonoBehaviour {
    public Animation setting_a;
    public AudioSource aud;
    void audplay()
    {
        aud.Play();
    }
    int cur_ani;
    void Start()
    {
        cur_ani = 0;
    }
    public void sound_on()
    {
        if (cur_ani == 1)
            return;
        cur_ani = 1;
        setting_a.Play("sound_on"); audplay();
    }
    public void alarm_on()
    {
        if (cur_ani == 2)
            return;
        cur_ani = 2;
        setting_a.Play("alarm_on"); audplay();
    }
    public void lang_on()
    {
        if (cur_ani == 3)
            return;
        cur_ani = 3; setting_a.Play("lang_on"); audplay();
    }
    public void power_on()
    {
        if (cur_ani == 4)
            return;
        cur_ani = 4; setting_a.Play("power_on"); audplay();
    }
}
