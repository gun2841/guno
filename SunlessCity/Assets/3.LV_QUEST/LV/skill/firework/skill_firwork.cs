using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Spine.Unity;
public class skill_firwork : MonoBehaviour {
    string[] firwork_name = {"firework","firework_circle", "firework_circle2", "firework_small_circle"
    , "firework_small_circle2","firework_spread", "firework_spread_small", "firework_spread_small2"};

    SkeletonGraphic skg;
    void Start()
    {

        skg.AnimationState.Complete += AnimationState_Complete;
    }
    void OnEnable()
    {
        int r = Random.Range(0, 8);
        skg = this.GetComponent<SkeletonGraphic>();
        skg.startingAnimation = firwork_name[r];
        skg.startingLoop = true;
        skg.timeScale = 1f;
        skg.Initialize(true);

    }

    private void AnimationState_Complete(Spine.TrackEntry trackEntry)
    {
        int r = Random.Range(0, 8);
        skg = this.GetComponent<SkeletonGraphic>();
        skg.startingAnimation = firwork_name[r];
        skg.Initialize(true);
        skg.AnimationState.Complete += AnimationState_Complete;
    }

    void OnDisable()
    {
        skg = null;
    }
}
