import torch
from torch.utils.data import Dataset, DataLoader
from PIL import Image
from datasets import load_dataset
from torchvision import transforms

class PetDataset(Dataset):
    def __init__(self, split="train", transform=None):
        self.split = split
        self.dataset = load_dataset("timm/oxford_iiit_pet", split=split, token="hf_TXBZZgyLnKNeQooKBARuuClfTHW")
        self.transform = transform

    def __len__(self):
        return len(self.dataset)

    def __getitem__(self, idx):
        example = self.dataset[idx]
        image = example["image"]
        label = example["label"]
        if image.mode != "RGB":
            image = image.convert("RGB")
        if self.transform:
            image = self.transform(image)
        return {"pixel_values": image, "labels": torch.tensor(label, dtype=torch.long)}

def get_dataloaders(batch_size=32):
    transform = transforms.Compose([
        transforms.Resize(64),
        transforms.CenterCrop(64),
        transforms.RandomHorizontalFlip(),
        transforms.ToTensor(),
        transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225]),
    ])
    
    train_dataset = PetDataset(split="train", transform=transform)
    val_dataset = PetDataset(split="test", transform=transform)
    
    train_loader = DataLoader(train_dataset, batch_size=batch_size, shuffle=True, pin_memory=True)
    val_loader = DataLoader(val_dataset, batch_size=batch_size, shuffle=False, pin_memory=True)
    
    return train_loader, val_loader