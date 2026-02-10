# data.py
import torchvision
from torch.utils.data import DataLoader
from torchvision import transforms

def get_data_loaders():
    transform = transforms.Compose([
        transforms.ToTensor(),
        transforms.Normalize((0.5,), (0.5,))  # Для MNIST (1 канал)
    ])

    trainset = torchvision.datasets.MNIST(
        root='./data', train=True, download=True, transform=transform)
    testset = torchvision.datasets.MNIST(
        root='./data', train=False, download=True, transform=transform)

    trainloader = DataLoader(trainset, batch_size=4, shuffle=True, num_workers=2)
    testloader = DataLoader(testset, batch_size=4, shuffle=False, num_workers=2)

    return trainloader, testloader