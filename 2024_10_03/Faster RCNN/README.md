# Digging Practice :

For COCO dataset (Detectron 2’s default), [load_coco_json](https://github.com/facebookresearch/detectron2/blob/main/detectron2/data/datasets/coco.py#L29-L194) function plays the role.

The annotations are converted to Instances by [this](https://github.com/facebookresearch/detectron2/blob/main/detectron2/data/detection_utils.py#L234-L257) function called in the dataset mapper

-------------------------------------------------------------------------------------------------------------------------------------------------------------

# DebuggerCafe faster RCNN impl [Source](https://debuggercafe.com/a-simple-pipeline-to-train-pytorch-faster-rcnn-object-detection-model/)

```python
def collate_fn(batch):
    return tuple(zip(*batch))
```
batch = [
    (image1, {'boxes': torch.tensor([[50, 60, 150, 200], [120, 130, 170, 220]]), 'labels': torch.tensor([1, 2])}),
    (image2, {'boxes': torch.tensor([[30, 40, 100, 120]]), 'labels': torch.tensor([3])})
]

When the collate_fn is applied:

zip(*batch) separates the images and targets:

```
images = (image1, image2)
targets = ({'boxes': tensor([[50, 60, 150, 200], [120, 130, 170, 220]]), 'labels': tensor([1, 2])},
           {'boxes': tensor([[30, 40, 100, 120]]), 'labels': tensor([3])})
```
Output of collate_fn:
```
return (images, targets)
```

# Detectron 2 medium post [here](https://medium.com/@hirotoschwert/digging-into-detectron-2-47b2e794fabd)

The box head is one of the sub-classes of ROI Heads. For example Mask R-CNN has more ROI heads such as a mask head.

FPN: One pixel of ‘P6’ feature corresponds to broader area of input image than ‘P2’- in other words ‘P6’ has a larger receptive field than ‘P2’.

[Example](https://github.com/facebookresearch/detectron2/blob/e0bffda3f503bc4caa1ae2360520db3591fd291d/detectron2/modeling/backbone/resnet.py#L442) of digging

