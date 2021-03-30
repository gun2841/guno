using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using System.Collections.Generic;
using System.Collections;
public class Dnditem : MonoBehaviour, IBeginDragHandler, IDragHandler, IEndDragHandler {
    public static bool dragDisabled = false;

    public static Dnditem draggedItem;
    public static GameObject icon;
    public static DndCell sourceCell;

    public int width;
    public string spine_name;
    public string thema;
    public int target_;
    public int index_;

    public delegate void DragEvent(Dnditem item);
    public static event DragEvent OnItemDragStartEvent;
    public static event DragEvent OnItemDragEndEvent;


    private static Canvas canvas;
    private static string cavasName = "DnDCanvas";
    private static int canvasSortOrder = 100;
    ///
    void Awake()
    {
       
        if (canvas == null)
        {
            GameObject canvasObj = new GameObject(cavasName);
            canvas = canvasObj.AddComponent<Canvas>();
            canvas.renderMode = RenderMode.ScreenSpaceOverlay;
            canvas.sortingOrder = canvasSortOrder;
            //canvas = GameObject.Find("MainCanvas").GetComponent<Canvas>();
        }
    }

    public void OnBeginDrag(PointerEventData eventData)
    {
        if (transform.parent.GetComponent<DndCell>().cellType == DndCell.CellType.DropOnly) { return; }
        if (dragDisabled == false)
        {
        
            sourceCell = GetCell();
            draggedItem = this;
            // base 이미지 
            icon = new GameObject();
            icon.transform.SetParent(canvas.transform);
            icon.name = "Icon";
            Image myImage = GetComponent<Image>();
            myImage.raycastTarget = false;
            Image iconImage = icon.AddComponent<Image>();
            iconImage.raycastTarget = false;
            iconImage.sprite = myImage.sprite;
            iconImage.color = myImage.color;
            RectTransform iconRect = icon.GetComponent<RectTransform>();
            iconImage.type = Image.Type.Sliced;

            // 안쪽 아이콘
             width = GetComponentInParent<test_info>().width_;
            spine_name = GetComponentInParent<test_info>().name_;
            thema = GetComponentInParent<test_info>().thema;
            index_ = GetComponentInParent<test_info>().index;
                //
            GameObject  con_img = new GameObject();
            con_img.transform.SetParent(icon.transform);
            con_img.name = "con_img";
            Image con_myImage = myImage.GetComponent<Transform>().GetChild(0).GetComponent<Image>();
            con_myImage.raycastTarget = false;
            Image con_iconImage = con_img.AddComponent<Image>();
            con_iconImage.raycastTarget = false;
            con_iconImage.sprite = con_myImage.sprite;
            RectTransform con_Rect = con_img.GetComponent<RectTransform>();

            con_Rect.sizeDelta = new Vector2(60,60);
            con_Rect.localPosition = new Vector2(0, 0);

            //
            iconRect.pivot = new Vector2(0.5f, 0.5f);
            iconRect.anchorMin = new Vector2(0.5f, 0.5f);
            iconRect.anchorMax = new Vector2(0.5f, 0.5f);
            iconRect.sizeDelta = new Vector2(96* width, 96);
           

            if (OnItemDragStartEvent != null)
                OnItemDragStartEvent(this);
        }
    }

    public void OnDrag(PointerEventData data)
    {
        if (icon != null)
            icon.transform.position = Input.mousePosition;
    }
    public void OnEndDrag(PointerEventData eventData)
    {
        ResetConditions();
    }
    private void ResetConditions()
    {
        if (icon != null)
            Destroy(icon);

        if (OnItemDragEndEvent != null)
            OnItemDragEndEvent(this);

        draggedItem = null;
        icon = null;
        sourceCell = null;
    }
    public void MakeRaycast(bool condition)
    {
        Image image = GetComponent<Image>();
        if (image != null)
            image.raycastTarget = condition;
    }
    public DndCell GetCell()
    {
        return GetComponentInParent<DndCell>();
    }
    void OnDisable()
    {
        ResetConditions();
    }
}
