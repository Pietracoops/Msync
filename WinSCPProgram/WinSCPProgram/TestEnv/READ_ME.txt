 _________________________________________________________________________________________________
|																								  |
|                       %               `      `%`           .%`               `        `%``      |   
|        `%%          %%%`      `%%%%%%%%%%:   %%%`       .%%%%`  %%          %%`    `%%%%%%%%    |   
|        %%%%       %%%%%     `%%%%%`    %%%    %%%`   .%%%%.    %%%:        -%%    %%%.   .%%    |   
|      `%%.%%%   `%%%%%%%     .%%%%%`            %%%%%%%%.      :%%%%%`     `%%   .%%.            |
|     .%%`  %%%%%%%% %%%       `.%%%%%%%%.        %%%%%`       .%%  %%%%.  `%%   %%%              |  
|    :%%    %%%%%    %%%    %%        `%%%`       %%%`         %%     .%%%%%%   `%%               |
|  `%%.     %%%      %%%   `%%%%%%%%%%%%%%        %%.         %%`        `%%`    %%%.......%%`    |   
|  %%`       %       %%%   `%%%%%%%%%%%          %%.         `%`          %`     `%%%%%%%%        |   
|                                               %%:                                               |   
|                                              `%%                                                |   
|                                              %%                                                 |   
|                                              ``                                                 | 										   
|_________________________________________________________________________________________________|

Written by: Massimo Pietracupa

Uses:											  
------------------------------------------------------OPENSSH--------------------------------------------------------------------------

OpenSSH is the open-source version of the Secure Shell (SSH) tools used by administrators of Linux and other non-Windows for cross-platform management 
of remote systems. OpenSSH has been added to Windows as of autumn 2018, and is included in Windows 10 and Windows Server 2019.

SSH is based on a client-server architecture where the system the user is working on is the client and the remote system being managed is the server. 
OpenSSH includes a range of components and tools designed to provide a secure and straightforward approach to remote system administration, including:

sshd.exe, which is the SSH server component that must be running on the system being managed remotely
ssh.exe, which is the SSH client component that runs on the user's local system
ssh-keygen.exe generates, manages and converts authentication keys for SSH
ssh-agent.exe stores private keys used for public key authentication
ssh-add.exe adds private keys to the list allowed by the server
ssh-keyscan.exe aids in collecting the public SSH host keys from a number of hosts
sftp.exe is the service that provides the Secure File Transfer Protocol, and runs over SSH
scp.exe is a file copy utility that runs on SSH
Documentation in this section focuses on how OpenSSH is used on Windows, including installation, and Windows-specific configuration and use cases.
Here are the topics:

Installing and Uninstalling OpenSSH For Windows Server 2019 and Windows 10
Additional detailed documentation for common OpenSSH features is available online at OpenSSH.com.

The master OpenSSH open source project is managed by developers at the OpenBSD Project. The Microsoft fork of this project is in Github. 
Feedback on Windows OpenSSH is welcomed and can be provided by creating Github issues in our OpenSSH Github repo.


----------------------------------------------------WINSCP-------------------------------------------------------------------------------

WinSCP (Windows Secure Copy) is a free and open-source SFTP, FTP, WebDAV, Amazon S3 and SCP client for Microsoft Windows. Its main function is 
secure file transfer between a local and a remote computer. Beyond this, WinSCP offers basic file manager and file synchronization functionality. 
For secure transfers, it uses Secure Shell (SSH) and supports the SCP protocol in addition to SFTP.[3]

Development of WinSCP started around March 2000 and continues. Originally it was hosted by the University of Economics in Prague, where its author 
worked at the time. Since July 16, 2003, it is licensed under the GNU GPL and hosted on SourceForge.net.[4]

WinSCP is based on the implementation of the SSH protocol from PuTTY and FTP protocol from FileZilla.[5] It is also available as a plugin for Altap 
Salamander file manager,[6] and there exists a third-party plugin for the FAR file manager.[7]





                       %               `      `%`           .%`               `        `%``         
        `%%          %%%`      `%%%%%%%%%%:   %%%`       .%%%%`  %%          %%`    `%%%%%%%%       
        %%%%       %%%%%     `%%%%%`    %%%    %%%`   .%%%%.    %%%:        -%%    %%%.   .%%       
      `%%.%%%   `%%%%%%%     .%%%%%`            %%%%%%%%.      :%%%%%`     `%%   .%%.           
     .%%`  %%%%%%%% %%%       `.%%%%%%%%.        %%%%%`       .%%  %%%%.  `%%   %%%                
    :%%    %%%%%    %%%    %%        `%%%`       %%%`         %%     .%%%%%%   `%%              
  `%%.     %%%      %%%   `%%%%%%%%%%%%%%        %%.         %%`        `%%`    %%%.......%%`       
  %%`       %       %%%   `%%%%%%%%%%%          %%.         `%`          %`     `%%%%%%%%           
                                               %%:                                                  
                                              `%%                                                   
                                              %%                                                    
                                              ``                                                  	