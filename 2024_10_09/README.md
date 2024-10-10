[Colab](https://colab.research.google.com/drive/1VoYNfYDKcKRQRor98Zbf2-9VQTtGJ24k?usp=sharing) QLoRA LLM

### TensorFloat-32 (TF32) on Ampere (and later) devices

Starting in PyTorch 1.7, there is a new flag called allow_tf32. This flag defaults to True in PyTorch 1.7 to PyTorch 1.11, and False in PyTorch 1.12 and later. This flag controls whether PyTorch is allowed to use the TensorFloat32 (TF32) tensor cores, available on NVIDIA GPUs since Ampere, internally to compute matmul (matrix multiplies and batched matrix multiplies) and convolutions.

In CUDA programming, blocking refers to whether a function or operation waits for the GPU to complete its execution before allowing the CPU to proceed.

- Synchronous (blocking) vs asynchronous (non-blocking) operation

PyTorch CUDA [manual]()

```python
cuda = torch.device('cuda')
s = torch.cuda.Stream()  # Create a new stream.
A = torch.empty((100, 100), device=cuda).normal_(0.0, 1.0)
s.wait_stream(torch.cuda.default_stream(cuda))  # NEW!
with torch.cuda.stream(s):
    B = torch.sum(A)
A.record_stream(s)  # NEW!
```

- s.wait_stream(torch.cuda.default_stream(cuda)): This ensures that the newly created stream s waits for all operations on the default stream (like the normal_() initialization of A) to finish before executing any operation on stream s. This prevents the sum operation from starting prematurely.

- A.record_stream(s): This records the stream s to the tensor A. This step ensures that any further use of A on different streams (such as memory deallocation or reuse) will respect the operations on s and only occur after all operations on s involving A are completed.

-------------------------------------------------------------------------------------------------------------------

In prior versions of PyTorch (1.9 and earlier), the autograd engine always synced the default stream with all backward ops, so the following pattern:

```python
with torch.cuda.stream(s):
    loss.backward()
use grads
```
was safe as long as use grads happened on the default stream. In present PyTorch, that pattern is no longer safe. If backward() and use grads are in different stream contexts, you must sync the streams:

```python
with torch.cuda.stream(s):
    loss.backward()
torch.cuda.current_stream().wait_stream(s)
use grads
```
even if use grads is on the default stream.
