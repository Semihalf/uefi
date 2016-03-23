/*++

Copyright (c) 2004 - 2006, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials                          
are licensed and made available under the terms and conditions of the BSD License         
which accompanies this distribution.  The full text of the license may be found at        
http://opensource.org/licenses/bsd-license.php                                            
                                                                                          
THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  


Module Name:

  LinkedList.c
  
Abstract: 

  Linked List Library Functions.

--*/
#include "usb-xhci-compat.h"
/**
  Initializes the head node of a doubly linked list, and returns the pointer to
  the head node of the doubly linked list.

  Initializes the forward and backward links of a new linked list. After
  initializing a linked list with this function, the other linked list
  functions may be used to add and remove nodes from the linked list. It is up
  to the caller of this function to allocate the memory for ListHead.

  If ListHead is NULL, then ASSERT().

  @param  ListHead  A pointer to the head node of a new doubly linked list.

  @return ListHead

**/
LIST_ENTRY *
//EFIAPI
/*Glue*/InitializeListHead (
  IN OUT  LIST_ENTRY            *List
  )

{
  ASSERT (List != NULL);

  List->ForwardLink = List;
  List->BackLink = List;
  return List;
}

/**
  Removes a node from a doubly linked list, and returns the node that follows
  the removed node.

  Removes the node Entry from a doubly linked list. It is up to the caller of
  this function to release the memory used by this node if that is required. On

  exit, the node following Entry in the doubly linked list is returned. If
  Entry is the only node in the linked list, then the head node of the linked
  list is returned.

  If Entry is NULL, then ASSERT().
  If Entry is the head node of an empty list, then ASSERT().
  If PcdMaximumLinkedListLength is not zero, and the number of nodes in the
  linked list containing Entry, including the Entry node, is greater than
  or equal to PcdMaximumLinkedListLength, then ASSERT().

  @param  Entry A pointer to a node in a linked list

  @return Entry

**/
LIST_ENTRY *
/*EFIAPI
  Glue*/RemoveEntryList (
  IN      CONST LIST_ENTRY      *Entry
  )
{
  ASSERT (!IsListEmpty (Entry));

  Entry->ForwardLink->BackLink = Entry->BackLink;
  Entry->BackLink->ForwardLink = Entry->ForwardLink;
  return Entry->ForwardLink;
}

/**
  Adds a node to the beginning of a doubly linked list, and returns the pointer
  to the head node of the doubly linked list.

  Adds the node Entry at the beginning of the doubly linked list denoted by
  ListHead, and returns ListHead.

  If ListHead is NULL, then ASSERT().
  If Entry is NULL, then ASSERT().
  If ListHead was not initialized with InitializeListHead(), then ASSERT().
  If PcdMaximumLinkedListLenth is not zero, and prior to insertion the number
  of nodes in ListHead, including the ListHead node, is greater than or
  equal to PcdMaximumLinkedListLength, then ASSERT().

  @param  ListHead  A pointer to the head node of a doubly linked list.
  @param  Entry     A pointer to a node that is to be inserted at the beginning
                    of a doubly linked list.

  @return ListHead

**/
LIST_ENTRY *
/* EFIAPI */
/* Glue */InsertHeadList (
  IN OUT  LIST_ENTRY            *List,
  IN OUT  LIST_ENTRY            *Entry
  )
{
  //
  // ASSERT List not too long and Entry is not one of the nodes of List
  //
  ASSERT (!IsNodeInList (List, Entry));

  Entry->ForwardLink = List->ForwardLink;
  Entry->BackLink = List;
  Entry->ForwardLink->BackLink = Entry;
  List->ForwardLink = Entry;
  return List;
}
