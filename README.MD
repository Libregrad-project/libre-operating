# Libre Operating Systsem

Welcome to the official repository of the Libre Operating System. Within
this repository, you will be able to find the source code, and needed documentation.

# Technical Information

Let's dive into some technical information about the operating system, both theory and partical.
The operating system is what we call a CIOS, which stands for Crypto Integrated Operating System,
the operating system has an integrated blockchain, which is actually where the operating system
is build into. You can not fully disable the blockchain, since this is where the operating system runs on,
but what you can do is disconnect it, it will not sync anymore. We recommend to keep the blockchain on,
since our updates are also going trough the chain. We will have *alternative* ways of updating the system,
so it is not required to keep it on.

The Libre Operating System is following secure standards regarding key management and security.
We encrypt our communications between our nodes and your devices with TLS 1.3 or higher. We also use authenticated amd encrypted
P2P protocols for blockchain communication.

We are using mainly open-source protocols and standards, to ensure the user and the community knows exactly how we securly handle
data and communication. Whenever a security issue is found within any open-source protocol we use, our team will patch it, and return
the entire pached code to the community and it's original repository. If the repository does not accept fixes, or is inactive, we will
create a brand new repository keeping all credits to the original owner and maintainer.

# File Systsem (FS)

The Libre Operating Systsem utilizes its own custom-designed File System called PFS (Proof File Systsem).
Unlike traditional file systems such as ext2/4 or FAT, PFS is built from the ground up with a focus on security,
integrity and blockchain-inspired data-structures.

PFS not only incorporates blockchain-inspired data structures but also emphasizes encyrpted storage, scalability, performance, fault tolorance and recovery, as well as flixable
metadata and access control. Our file system includes the very advanced metadata support, for example, you can specify a .pfsm file inside a directory, which contains detailed information about
that directory. This allows you to link filenames to human-readable titles and much more, enabling richer context and orginization.

We also ensure that all these advanced features do not impact your system's performance. PFS leverages advanced caching, intelligent storage management, and optimized control
algorithms to maintain high troughput.

To improve reliability, PFS includes robust fault tolerance mechanisms such as crash recovery and corruption detection, minimzing the risk of data-loss during unexpcted power failures or system crashes.

Unlike traditional Linux file systems, when you delete files or modify partitions in PFS, you are provided with clear, proof-backed security features that make you fully aware of the impact
your actions can have.

# Performance

We focus on maintaining performance within our systems, we use effective blockchain syncing, pruning and storing. We also focus on modulatiry, every aspect is coded as a "module", which is controlable, and updateable seperatly
from the system. This ensures if something goes sideways within the updates, only that specific module will have issues. This makes downgrading a lot easier, without causing sytsem downtime or issues.

# Design Choices

For this massive, yet important project, we have decided to use proper toolchains, build tools and more. To make developing, scaling and updating a lot easier. Everyone is able to compile the source-code by themself,
we do need to note, with self-compiling it can take some time to finish, since you will need to compile our toolchain and then the full operating system. Instead we recommend if you are not a developer, but a user, to use
the pre-compiled releases, they are available both on our website and within this repository release section.

The operating system kernel is designed to be a hybrid-kernel, including the blockchain both as service and embedded.
The embedded (Kernel-level) serves for trusted validation, we will embed a thin, essential part of the blockchain logic in the kernel, which will:

- Verify signed updates before loading them. (Like bootloader & kernel module validation.)
- Enforce execution policies (eg. "Only run apps apporved on-chain.")
- Ensure early-stage OS integrity (Before user-space even loads.)
- Validates the state of the system during critical ops (boot, app execution and updates.)

All this will make the Operating System blockchain-secured from boot time.

We also have a service (User-Space), for full node logic. This will run a full blockchain node in the user-space to:

- Sync with the network
- Validate blocks, participate in consensus (PoS, PoW ...)
- Manage the ledger that tracks OS/Application updates
- Serve data to the kernel-level validator trough IPC or syscall interface.

This can be modular, update frequently, and distributed like any regular software.

For security, the operating system updates are only accepted if they're signed and published on the blockchain.

For the embedded side (Kernel) we will need:

- Lightweight Merkle tree validation
- Signature verfication (eg. ED25519, ECDSA)
- Trusted block header sync interface
- App/driver loader hooked into the validator

Then, for the service side (Userland), we will need:

- Full node implementation
- P2P networking stack
- Chain state manager (Custom Storage ?)
- Update publisher/installer module

The kernel will need to validate the signatures, hash apps/packages and compare against on-chain Merkle roots or hashlists, and maybe reject syscalls or apps execs that are not trusted.
for the rejection system, we will make a seperate module, which will check on-chain which apps are trusted. For syscalls, we will implement a default set of allowed instructions, whenever
a unknown call comes, the user will need to approve it or decline, if it's not safe, it will automaticly be locked by the system, even with an approved signature. Users are then able to unlock
it from the defender section.

# Defender

The defender is a security system, it checks on the chain if an app or syscall is approved, and if not it will lock that application or call. The user can enable and disable defender. When disabling the defender
there will be a few warning, because, it's not secure to disable a protection mechanism. If a populair app for example is ported to our platform, and it is not signed, user's can request the core development team of this
operating system to validate it. Most of the time, it will possible only be accepted whenever we have direct contact with the app developer, we want to maintain the most secure operating system, so users can feel safe.

# Validate Applications

Any user can submit their app metadata, hash of the binary, dwnload URI and a fee of 100 LBR, the fee of 100LBR is done to prevent scams and spam uploads. They submit this as a transaction, with the type of "submit_app". We will put a example transaction format below.
After submission, a review member will review the application manually off-chain, and audits for security, malware etc. When approved, the team signs an approval transaction using their validator key.

Whenever it is approved, a approval transaction will be initialized, which will return the 100 LBR and adds a hash to a trusted app registry on the chain. Apps who don't follow the guidelines, will possibly get their app trust recocked, using a revoke transaction. We apply
a warning system before we actually revoke the application.

Here is the example submission On-Chain transaction format, in Json:
{
	"type": "submit_app",
	"app_id": "com.example.example",
	"version": "0.0.1",
	"binary_hash": "SHA256 Hash Here",
	"metadata": { "author": "yourname", "desc": "Description"},
	"uri": "https://app.example.com/app.pkg"
}

We have a non-refundable fee, which is the fee needed to submit your application, that fee is ~ 100 LBR, we also have a refundable stake which is only returned if the application is approved,
the refundable stake is ~ 200 LBR.
 
