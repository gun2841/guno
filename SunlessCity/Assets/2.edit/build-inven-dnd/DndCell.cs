using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using System.Collections;

[RequireComponent(typeof(Image))]
public class DndCell : MonoBehaviour, IDropHandler
{

    public enum CellType
    {
        DragOnly, DropOnly
    }
    public CellType cellType = CellType.DragOnly;


    public bool unlimitedSource = false;

    private Dnditem mydadItem;

    void OnEnable()
    {
        Dnditem.OnItemDragStartEvent += OnAnyItemDragStart;
        Dnditem.OnItemDragEndEvent += OnAnyItemDragEnd;
        UpdateMyItem();

    }
    void OnDisable()
    {
        Dnditem.OnItemDragStartEvent-= OnAnyItemDragStart;
        Dnditem.OnItemDragEndEvent -= OnAnyItemDragEnd;
        StopAllCoroutines();
    }
    private void OnAnyItemDragStart(Dnditem item)
    {
        UpdateMyItem();
        if (mydadItem != null)
        {
            mydadItem.MakeRaycast(false);
            if (mydadItem == item)
            {
                if (cellType == CellType.DropOnly)
                    Dnditem.icon.SetActive(false);
            }
        }
    }
    private void OnAnyItemDragEnd(Dnditem item)
    {
        UpdateMyItem();
        if (mydadItem != null)
        {
            mydadItem.MakeRaycast(true);
        }
    }
    public void OnDrop(PointerEventData data)
    {

        RectTransform rt = GetComponent<RectTransform>();
        Vector3 vt3 = new Vector3(0.5f, 0, 0);
        bool dir = false;
        if (data.position.x > Camera.main.WorldToScreenPoint(rt.position + vt3).x)
        {
            dir = true;
        }
        else
        {
            dir = false;
        }
        int check_value = buildmgr.Instance.building_check(int.Parse(transform.parent.name), int.Parse(name), dir, Dnditem.draggedItem);
        if (check_value != -1)
        {

        }
        else
        {
            return;
        }

        if (Dnditem.icon != null)
        {
            Dnditem item = Dnditem.draggedItem;
            DndCell soureceCell = Dnditem.sourceCell;

            if (Dnditem.icon.activeSelf == true)
            {
                if ((item != null) && (soureceCell != this))
                {
                    if (cellType == CellType.DropOnly)
                    {
                        item.target_ = check_value;
                        PlaceItem(item, dir);
                    }
                }
            }
            if (item != null)
            {
                if (item.GetComponentInParent<DndCell>() == null)
                    Destroy(item.gameObject);
            }
            UpdateMyItem();
            soureceCell.UpdateMyItem();

        }
    }

    public void PlaceItem(Dnditem item, bool dir)
    {
        if (item != null)
        {
            DestroyItem();
            mydadItem = null;
            DndCell cell = item.GetComponentInParent<DndCell>();
            if (cell != null)
            {
                if (cell.unlimitedSource == true)
                {
                    string itemName = item.name;
                    item = Instantiate(item);
                    item.name = itemName;
                }
            }
            item.transform.SetParent(transform, false);
            if (item.width % 2 == 1)
            {
                item.GetComponent<RectTransform>().sizeDelta = new Vector2(96 * item.width, 96);
            }
            else
            {
                RectTransform rt = item.GetComponent<RectTransform>();
                if (dir)
                {

                    rt.anchoredPosition = new Vector2(rt.anchoredPosition.x + 48, rt.anchoredPosition.y);
                    rt.sizeDelta = new Vector2(96 * item.width, 96);
                }
                else
                {

                    rt.anchoredPosition = new Vector2(rt.anchoredPosition.x - 48, rt.anchoredPosition.y);
                    rt.sizeDelta = new Vector2(96 * item.width, 96);
                }
            }

            item.GetComponent<RectTransform>().GetChild(0).GetComponent<RectTransform>().sizeDelta
       = new Vector2(60, 60);



             item.MakeRaycast(true);
            mydadItem = item;
        }
    }
    public void DestroyItem()
    {
        UpdateMyItem();
        if (mydadItem != null)
        {
            if (mydadItem != null)
                Destroy(mydadItem.gameObject);
        }
        mydadItem = null;
    }
    public void UpdateMyItem()
    {
        
     mydadItem = GetComponentInChildren<Dnditem>();
    }
    public Dnditem GetItem()
    {
        return mydadItem;
    }
    public void RemoveItem()
    {
        DestroyItem();
    }

}