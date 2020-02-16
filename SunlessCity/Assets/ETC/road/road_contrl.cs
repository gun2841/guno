using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Spine.Unity;
public class road_contrl : MonoBehaviour
{
    private SkeletonGraphic skg;
    // Use this for initialization
    void Start()
    {
        skg = this.GetComponent<SkeletonGraphic>();

          skg.AnimationState.SetAnimation(0, "b_ld_tr_v3_c", true);
            StartCoroutine("train_control");
       // StartCoroutine("car_control");
    }
    IEnumerator train_control()
    {
        yield return new WaitForSeconds(0.5f);
        skg.AnimationState.SetAnimation(1, "ani_tr_ld", true);
        yield return null;
    }
    IEnumerator car_control()
    {
        for (int i = 1; i < 13; i++)
        {
            skg.AnimationState.SetAnimation(i, "ani_car_ld_kr" + i.ToString() + "_1", true);
            yield return new WaitForSeconds(Random.Range(2.0f, 2.5f));
        }
    }

}