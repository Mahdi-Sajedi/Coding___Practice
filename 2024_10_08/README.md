## kahan summation algorithm [wiki](https://en.m.wikipedia.org/wiki/Kahan_summation_algorithm)


try to understand. looks interesting

## summed-area table [wiki](https://en.m.wikipedia.org/wiki/Summed-area_table)

data structure, image processing

## opencv [image thresholding](https://docs.opencv.org/4.x/d7/d4d/tutorial_py_thresholding.html)

math understood: find a threshold that minimizes within/intra class variance

python implementation

Exercises

There are some optimizations available for Otsu's binarization. You can search and implement it.

wikipedia:

```python
def otsu_intraclass_variance(image, threshold):
    """
    Otsu's intra-class variance.
    If all pixels are above or below the threshold, this will throw a warning that can safely be ignored.
    """
    return np.nansum(
        [
            np.mean(cls) * np.var(image, where=cls)
            #   weight   ·  intra-class variance
            for cls in [image >= threshold, image < threshold]
        ]
    )
```


## Burovka's algorithm [wikipedia](https://en.m.wikipedia.org/wiki/Borůvka%27s_algorithm)

gready, minimum spanning tree/forest, O(ElogV)


## Captum [Github](https://github.com/pytorch/captum?tab=readme-ov-file)

pytorch, model interpretability

- ### Look at end of readme to see 10s of papers on algorithms used in Captum

## Stackexchange [link](https://stackoverflow.com/questions/70758474/pytorch-is-creating-non-empty-tensor-with-torch-emptyx-y)

If you want a tensor of zeros, use torch.zeros.

torch.empty allocates a tensor but it does not initialise the contents, meaning that the tensor will contain whatever data happened to occupy that region of memory already.

## [cppreference: std::inner_product](https://en.cppreference.com/w/cpp/algorithm/inner_product)

Notes
The parallelizable version of this algorithm, std::transform_reduce, requires op1 and op2 to be commutative and associative, but std::inner_product makes no such requirement, and always performs the operations in the order given.


# [From Sensor output to RGB image](https://adaptivesupport.amd.com/s/article/889426?language=en_US)

This document explains the process of converting sensor output to an RGB image, specifically focusing on the use of Xilinx devices (now owned by AMD) for this task. Here's a breakdown:

Key Points:
Image Sensors:

CCD and CMOS sensors: These are the two main types of image sensors used to capture light and convert it into electric signals.
Pixels: The sensor is an array of pixels, where each pixel gathers photons during the exposure time, translating into intensity values.
Color Filter Array (CFA):

To capture color, sensors use a Color Filter Array (CFA) like the Bayer filter, which applies a specific color filter (Red, Green, or Blue) to each pixel.
However, each pixel captures information for only one color, and the missing color components are calculated through a process called demosaicing.
Demosaicing (or DeBayerization):

Demosaicing reconstructs the full RGB values for each pixel by interpolating the missing color channels.
This process is particularly important in converting the raw sensor data to a usable RGB image.
Xilinx Devices for Demosaicing:

Xilinx (now part of AMD) offers specific IP (Intellectual Property) cores like the Sensor Demosaic IP (PG286) that handle demosaicing in hardware.
The tutorial focuses on using this IP with Vivado 2018.1 to simulate how a sensor’s raw data (Bayer format) can be converted into RGB using Xilinx devices.
Vivado Simulation:

The tutorial shows how to set up a simulation in Vivado, configure the Bayer filter, and run a behavioral simulation that converts Bayer-encoded images into RGB images.
The simulation demonstrates the transition from an 8-bit single-channel (Bayer format) to 24-bit three-channel (RGB format).
Xilinx and AMD:
Xilinx was an independent company that developed FPGAs (Field Programmable Gate Arrays) and IP cores for various applications, including video processing.
In 2020, AMD acquired Xilinx, expanding its capabilities in hardware acceleration and programmable logic devices.
This tutorial essentially demonstrates how raw sensor data is processed and converted into an RGB image using Xilinx hardware, a process often used in image and video processing workflows.

# PIL to numpy 

```python
if format in ['BGR', 'YUV-BT.601']:
  image = image.convert('RGB')
if format == 'BGR':
  image = image[:,:,-1]
```

PIL (Python Imaging Library) primarily handles images in RGB format. It does not directly support other formats like BGR or YUV.
Therefore, even if the desired output format is BGR, the image must first be converted to RGB to ensure that PIL can work with it.
