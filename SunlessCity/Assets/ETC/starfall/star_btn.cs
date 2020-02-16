using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Spine.Unity;
public class star_btn : MonoBehaviour
{
    public SkeletonGraphic[] skg;
    int tt;
    void Start()
    {
        tt = skg.Length;
    }

    public void click_event()
    {
        int index = Random.Range(1, 7);
        int arg = Random.Range(0, tt);
        var trackEntry = skg[arg].AnimationState.GetCurrent(index);
        if (trackEntry != null)
        {
            if (trackEntry.IsComplete != true)
            {
                return;
            }
        }
        skg[arg].AnimationState.SetAnimation(index, "test" + index, false);
    }
}