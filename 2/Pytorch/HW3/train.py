# train.py 
import wandb
from data import get_data_loaders
from NN import Net
import torch.nn as nn
import torch
def main():
    wandb.init(project="mnist-training")
    trainloader, testloader = get_data_loaders()
    net = Net()
    criterion = nn.CrossEntropyLoss()
    optimizer = torch.optim.SGD(net.parameters(), lr=0.001, momentum=0.9)

    for epoch in range(2):
        running_loss = 0.0
        correct = 0
        total = 0
        for i, data in enumerate(trainloader, 0):
            inputs, labels = data
            optimizer.zero_grad()
            outputs = net(inputs)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()
            
            running_loss += loss.item()
            _, predicted = torch.max(outputs.data, 1)
            total += labels.size(0)
            correct += (predicted == labels).sum().item()
            
            if i % 2000 == 1999:
                wandb.log({
                    "loss": running_loss / 2000,
                    "accuracy": correct / total * 100
                })
                running_loss = 0.0
                correct = 0
                total = 0

    wandb.finish()
    torch.save(net.state_dict(), 'mnist_net.pth')

if __name__ == "__main__":
    main()