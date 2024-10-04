[Source](https://debuggercafe.com/a-simple-pipeline-to-train-pytorch-faster-rcnn-object-detection-model/)

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
