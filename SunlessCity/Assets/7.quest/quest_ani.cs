using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class quest_ani : MonoBehaviour
{
    public Animation quest_a;
    int cur_ani;
    public AudioSource aud;
    void audplay()
    {
        aud.Play();
    }
    void Start()
    {
        cur_ani = 0;
    }
    public void archive_on()
    {
        if (cur_ani == 1)
            return;
        quest_a.Play("Quest_archive"); audplay();
        cur_ani = 1;
    }
    public void day_by_on()
    {
        if (cur_ani == 2)
            return;
        quest_a.Play("Quest_day_by"); audplay();
        cur_ani = 2;
    }
}
