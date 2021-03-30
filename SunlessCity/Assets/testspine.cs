using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Spine.Unity;
public class testspine : MonoBehaviour {
    public SkeletonGraphic sk;
    // Use this for initialization
    void Start() {
        //    Spine.AnimationStateData stateData = new Spine.AnimationStateData(sk);
        // stateData.DefaultMix = 0.1f;
        //stateData.SetMix("6_b_o", "tr_rf", 0.2f);
        StartCoroutine("train");
    }
    IEnumerator train()
    {
        sk.AnimationState.SetAnimation(1, "tr_rf", true);
        while (true)
        {
            sk.AnimationState.SetAnimation(0, "6_b_b", false);
            yield return new WaitForSeconds(0.5f);
            sk.AnimationState.SetAnimation(0, "6_b_o", false);
            yield return new WaitForSeconds(0.5f);
            sk.AnimationState.SetAnimation(0, "3_b_b", false);
            yield return new WaitForSeconds(0.5f);
            sk.AnimationState.SetAnimation(0, "3_b_o", false);
            yield return new WaitForSeconds(0.5f);
            sk.AnimationState.SetAnimation(0, "2_b_b", false);
            yield return new WaitForSeconds(0.5f);
            sk.AnimationState.SetAnimation(0, "2_b_o", false);
            yield return new WaitForSeconds(0.5f);
        }
    }
    IEnumerator st()
    {
        while (true)
        {
            string basic = "b_v1_l2_";

            sk.AnimationState.SetAnimation(0, basic + 'o', true);
            yield return new WaitForSeconds(0.5f);
            sk.AnimationState.SetAnimation(0, basic + 'c', true);
            yield return new WaitForSeconds(0.5f);
            sk.AnimationState.SetAnimation(0, basic + 'b', true);
            yield return new WaitForSeconds(0.5f);
            sk.AnimationState.SetAnimation(0, basic + 'y', true);
            yield return new WaitForSeconds(0.5f);

            basic = "b_v2_l2_";
            sk.AnimationState.SetAnimation(0, basic + 'o', true);
            yield return new WaitForSeconds(0.5f);
            sk.AnimationState.SetAnimation(0, basic + 'c', true);
            yield return new WaitForSeconds(0.5f);
            sk.AnimationState.SetAnimation(0, basic + 'b', true);
            yield return new WaitForSeconds(0.5f);
            sk.AnimationState.SetAnimation(0, basic + 'y', true);
            yield return new WaitForSeconds(0.5f);

            basic = "b_v3_l2_";
            sk.AnimationState.SetAnimation(0, basic + 'o', true);
            yield return new WaitForSeconds(0.5f);
            sk.AnimationState.SetAnimation(0, basic + 'c', true);
            yield return new WaitForSeconds(0.5f);
            sk.AnimationState.SetAnimation(0, basic + 'b', true);
            yield return new WaitForSeconds(0.5f);
            sk.AnimationState.SetAnimation(0, basic + 'y', true);
            yield return new WaitForSeconds(0.5f);
            basic = "r_v3_l2_";
            sk.AnimationState.SetAnimation(1, basic + 'o', true);
            yield return new WaitForSeconds(0.5f);
            sk.AnimationState.SetAnimation(1, basic + 'c', true);
            yield return new WaitForSeconds(1.5f);
            sk.AnimationState.SetAnimation(1, basic + 'b', true);
            yield return new WaitForSeconds(1.5f);
            sk.AnimationState.SetAnimation(1, basic + 'y', true);
            yield return new WaitForSeconds(0.5f);
        }
    }
    public void s_button()
    {
        sk.AnimationState.SetAnimation(0, "b_v2_l3_b", true);

    }
}
