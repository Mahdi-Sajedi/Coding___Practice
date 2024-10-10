[Colab](https://colab.research.google.com/drive/1VoYNfYDKcKRQRor98Zbf2-9VQTtGJ24k?usp=sharing) QLoRA LLM

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
