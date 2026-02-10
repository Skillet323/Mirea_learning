import torch
import torch.optim as optim
from data import get_dataloaders
from NN import ViT
import torch.nn as nn
from torch.optim.lr_scheduler import CosineAnnealingLR
import wandb 

def train(model, train_loader, optimizer, criterion, device):
    model.train()
    train_loss = 0.0
    for batch in train_loader:
        images = batch["pixel_values"].to(device)
        labels = batch["labels"].to(device)
        outputs = model(images)
        loss = criterion(outputs, labels)
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        train_loss += loss.item()
    return train_loss / len(train_loader) 

def evaluate(model, val_loader, criterion, device):
    model.eval()
    val_loss = 0.0
    correct = 0
    total = 0
    with torch.no_grad():
        for batch in val_loader:
            images = batch["pixel_values"].to(device)
            labels = batch["labels"].to(device)
            outputs = model(images)
            val_loss += criterion(outputs, labels).item()
            _, predicted = outputs.max(1)
            total += labels.size(0)
            correct += predicted.eq(labels).sum().item()
    accuracy = correct / total
    return val_loss / len(val_loader), accuracy 

def main():
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    
    wandb.init(
        project="ViT-Pet-Classification",
        config={
            "epochs": 10,
            "batch_size": 32,
            "lr": 1e-3,
            "embed_dim": 384,
            "depth": 6,
            "num_heads": 12,
            "dataset": "Oxford-IIIT Pet"
        }
    )
    
    train_loader, val_loader = get_dataloaders(batch_size=wandb.config.batch_size)
    model = ViT(
        img_size=64,
        patch_size=16,
        embed_dim=wandb.config.embed_dim,
        depth=wandb.config.depth,
        num_heads=wandb.config.num_heads,
        num_classes=37
    ).to(device)
    
    # Оптимизатор и критерий
    optimizer = optim.AdamW(model.parameters(), lr=wandb.config.lr, weight_decay=0.01)
    criterion = nn.CrossEntropyLoss()
    scheduler = CosineAnnealingLR(optimizer, T_max=10)
    
    # Обучение
    for epoch in range(wandb.config.epochs):
        train_loss = train(model, train_loader, optimizer, criterion, device)
        val_loss, accuracy = evaluate(model, val_loader, criterion, device)
        scheduler.step()
        
        # Логирование метрик в wandb
        wandb.log({
            "epoch": epoch + 1,
            "train_loss": train_loss,
            "val_loss": val_loss,
            "accuracy": accuracy
        })
        
        print(f"Epoch {epoch+1}/{wandb.config.epochs}, Train Loss: {train_loss:.4f}, Val Loss: {val_loss:.4f}, Accuracy: {accuracy*100:.2f}%")
    
    # Завершение wandb
    wandb.finish()

if __name__ == "__main__":
    main()