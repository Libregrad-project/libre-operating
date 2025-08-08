# Libre Operating System

Welcome to the official Libre Operating System repository.

----

The Libre Operating System is a Operating System build on top of our own Blockchain Technology. Each user gets a wallet
upon installing, that wallet, will be your digital identity to everything on our Blockchain, think of App-Stores or specific Apps that
are including our Blockchain and SDK.

Our Operating System is made from the ground up, together with it's corresponding Blockchain. Our current version of the Blockchain
is build on-top of the CryptoNote and ByteCoin code base.

----

# Technical Overview

The Libre Operating System is following secure standards regarding Key Management and Security. We strive to use all safety features
we can. We Encypt our communication to our node's and your device with TLS 1.3 or higher. We also use authenticated and encrypted
P2P protocols for blockchain communication.

We are using mainly open-source protocols and standards, to ensure the trust and bond between our users and the core team. Whenever
a security issue is found, we will patch it, and re-give control to the community.

Our UI is all made from scratch, we want to keep our Operating System advanced yet simple to use.

----

# File System (FS)

The Libre Operating System utilizes its own custom-designed File System called PFS (Proof File System). Unlike traditional file systems such as ext2/4 or FAT, PFS is built from the ground up with a focus on security, integrity, and blockchain-inspired data structures to meet the demands of a modern crypto-based OS.

PFS not only incorporates blockchain-inspired data structures but also emphasizes encrypted storage, scalability, performance, fault tolerance and recovery, as well as flexible metadata and access control.

Our file system includes very flexible metadata support. For example, you can specify a .pfsm file inside a directory, which contains detailed information about that directory. This allows you to link filenames to human-readable titles and much more, enabling richer context and organization.

We also ensure that all these advanced features do not impact your system's performance. PFS leverages advanced caching, intelligent storage management, and optimized control algorithms to maintain high throughput.

To improve reliability, PFS includes robust fault tolerance mechanisms such as crash recovery and corruption detection, minimizing the risk of data loss during unexpected power failures or system crashes.

Unlike traditional Linux file systems, when you delete files or modify partitions in PFS, you are provided with clear, proof-backed security features that make you fully aware of the consequences of your actions
----

# Performance

We focus on performance, within our systems, Effective blockchain syncing, pruning and much more. We also focus on modularity, every aspect of the operating-system
is designed and made as a modular components, think of the Wallet, API, P2P Layer, all made seperate. This is done for easier updates and scaling.

----

# Blockchain Layer

Our blockchain runs in tandem with the Operating System. It is there to validate app signatures, storing system update proof, and allows users and developers to interact with decentralized components