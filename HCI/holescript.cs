using UnityEngine;
using System.Collections;

public class holescript : MonoBehaviour
{
    public GameObject OutPotal;
    public GameObject effect;

    void OnTriggerEnter(Collider _col)
    {

        if (_col.transform.name == "FPSController")
        {
            _col.transform.position = new Vector3(OutPotal.transform.position.x, OutPotal.transform.position.y, OutPotal.transform.position.z);

            Instantiate(effect, OutPotal.transform.position, Quaternion.identity);

            Destroy(effect, effect.GetComponent<ParticleSystem>().duration + 0.5f);
        }
    }
}
