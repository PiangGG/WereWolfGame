// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

#include "Net/UnrealNetwork.h"
#include "Engine/ActorChannel.h"
#include "NativeGameplayTags.h"
#include "Inventory/LyraInventoryItemDefinition.h"
#include "Inventory/LyraInventoryItemInstance.h"
UInventoryComponent::UInventoryComponent(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
//,InventoryList(this)
{
	SetIsReplicatedByDefault(true);
}

void UInventoryComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//DOREPLIFETIME(ThisClass, InventoryList);
	DOREPLIFETIME(ThisClass, InventoryPickup);
}

bool UInventoryComponent::CanAddItemDefinition(TSubclassOf<ULyraInventoryItemDefinition> ItemDef, int32 StackCount)
{
	//@TODO: Add support for stack limit / uniqueness checks / etc...
	return true;
}

ULyraInventoryItemInstance* UInventoryComponent::AddItemDefinition(TSubclassOf<ULyraInventoryItemDefinition> ItemDef,
	int32 StackCount)
{
	ULyraInventoryItemInstance* Result = nullptr;
	/*if (ItemDef != nullptr)
	{
		Result = InventoryList.AddEntry(ItemDef, StackCount);
	}*/
	return Result;
}

void UInventoryComponent::AddItemInstance(ULyraInventoryItemInstance* ItemInstance)
{
	//InventoryList.AddEntry(ItemInstance);
}

void UInventoryComponent::RemoveItemInstance(ULyraInventoryItemInstance* ItemInstance)
{
	//InventoryList.RemoveEntry(ItemInstance);
}

TArray<ULyraInventoryItemInstance*> UInventoryComponent::GetAllItems()
{
	//return InventoryList.GetAllItems();
	TArray<ULyraInventoryItemInstance*> Temp;
	return Temp;
}

ULyraInventoryItemInstance* UInventoryComponent::FindFirstItemStackByDefinition(
	TSubclassOf<ULyraInventoryItemDefinition> ItemDef) const
{
	/*for (const FLyraInventoryEntry& Entry : InventoryList.Entries)
	{
		ULyraInventoryItemInstance* Instance = Entry.Instance;

		if (IsValid(Instance))
		{
			if (Instance->GetItemDef() == ItemDef)
			{
				return Instance;
			}
		}
	}
*/
	return nullptr;
}

int32 UInventoryComponent::GetTotalItemCountByDefinition(TSubclassOf<ULyraInventoryItemDefinition> ItemDef) const
{
	int32 TotalCount = 0;
	/*for (const FLyraInventoryEntry& Entry : InventoryList.Entries)
	{
		ULyraInventoryItemInstance* Instance = Entry.Instance;

		if (IsValid(Instance))
		{
			if (Instance->GetItemDef() == ItemDef)
			{
				++TotalCount;
			}
		}
	}*/

	return TotalCount;
}

bool UInventoryComponent::ConsumeItemsByDefinition(TSubclassOf<ULyraInventoryItemDefinition> ItemDef,
	int32 NumToConsume)
{
	/*AActor* OwningActor = GetOwner();
	if (!OwningActor || !OwningActor->HasAuthority())
	{
		return false;
	}

	//@TODO: N squared right now as there's no acceleration structure
	int32 TotalConsumed = 0;
	while (TotalConsumed < NumToConsume)
	{
		if (ULyraInventoryItemInstance* Instance = UInventoryComponent::FindFirstItemStackByDefinition(ItemDef))
		{
			InventoryList.RemoveEntry(Instance);
			++TotalConsumed;
		}
		else
		{
			return false;
		}
	}
	

	return TotalConsumed == NumToConsume;
	*/
	return false;
}

bool UInventoryComponent::ReplicateSubobjects(UActorChannel* Channel, FOutBunch* Bunch, FReplicationFlags* RepFlags)
{
	bool WroteSomething = Super::ReplicateSubobjects(Channel, Bunch, RepFlags);

	/*for (FLyraInventoryEntry& Entry : InventoryList.Entries)
	{
		ULyraInventoryItemInstance* Instance = Entry.Instance;

		if (Instance && IsValid(Instance))
		{
			WroteSomething |= Channel->ReplicateSubobject(Instance, *Bunch, *RepFlags);
		}
	}*/

	return WroteSomething;
}
