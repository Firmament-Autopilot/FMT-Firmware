#ifndef __USB_REG_DEFINE_H__
#define __USB_REG_DEFINE_H__


#define   __I     volatile const       /*!< Defines 'read only' permissions                 */
#define   __O     volatile             /*!< Defines 'write only' permissions                */
#define   __IO    volatile             /*!< Defines 'read / write' permissions              */


/** 
  * @brief USB_OTG_Core_Registers
  */
typedef struct
{
 __IO uint32_t GOTGCTL;               /*!< USB_OTG Control and Status Register          000h */
  __IO uint32_t GOTGINT;              /*!< USB_OTG Interrupt Register                   004h */
  __IO uint32_t GAHBCFG;              /*!< Core AHB Configuration Register              008h */
  __IO uint32_t GUSBCFG;              /*!< Core USB Configuration Register              00Ch */
  __IO uint32_t GRSTCTL;              /*!< Core Reset Register                          010h */
  __IO uint32_t GINTSTS;              /*!< Core Interrupt Register                      014h */
  __IO uint32_t GINTMSK;              /*!< Core Interrupt Mask Register                 018h */
  __IO uint32_t GRXSTSR;              /*!< Receive Sts Q Read Register                  01Ch */
  __IO uint32_t GRXSTSP;              /*!< Receive Sts Q Read & POP Register            020h */
  __IO uint32_t GRXFSIZ;              /*!< Receive FIFO Size Register                   024h */
  __IO uint32_t DIEPTXF0_HNPTXFSIZ;   /*!< EP0 / Non Periodic Tx FIFO Size Register     028h */
  __IO uint32_t HNPTXSTS;             /*!< Non Periodic Tx FIFO/Queue Sts reg           02Ch */
  uint32_t Reserved30[2];             /*!< Reserved                                     030h */
  __IO uint32_t GCCFG;                /*!< General Purpose IO Register                  038h */
  __IO uint32_t CID;                  /*!< User ID Register                             03Ch */
  uint32_t  Reserved5[3];             /*!< Reserved                                040h-048h */
  __IO uint32_t GHWCFG3;              /*!< User HW config3                              04Ch */
  uint32_t  Reserved6;                /*!< Reserved                                     050h */ 
  __IO uint32_t GLPMCFG;              /*!< LPM Register                                 054h */
  __IO uint32_t GPWRDN;               /*!< Power Down Register                          058h */
  __IO uint32_t GDFIFOCFG;            /*!< DFIFO Software Config Register               05Ch */
   __IO uint32_t GADPCTL;             /*!< ADP Timer, Control and Status Register       60Ch */
    uint32_t  Reserved43[39];         /*!< Reserved                                058h-0FFh */
  __IO uint32_t HPTXFSIZ;             /*!< Host Periodic Tx FIFO Size Reg               100h */
  __IO uint32_t DIEPTXF[0x0F];        /*!< dev Periodic Transmit FIFO */
} USB_OTG_GlobalTypeDef;



/** 
  * @brief USB_OTG_device_Registers
  */
typedef struct 
{
  __IO uint32_t DCFG;            /*!< dev Configuration Register   800h */
  __IO uint32_t DCTL;            /*!< dev Control Register         804h */
  __IO uint32_t DSTS;            /*!< dev Status Register (RO)     808h */
  uint32_t Reserved0C;           /*!< Reserved                     80Ch */
  __IO uint32_t DIEPMSK;         /*!< dev IN Endpoint Mask         810h */
  __IO uint32_t DOEPMSK;         /*!< dev OUT Endpoint Mask        814h */
  __IO uint32_t DAINT;           /*!< dev All Endpoints Itr Reg    818h */
  __IO uint32_t DAINTMSK;        /*!< dev All Endpoints Itr Mask   81Ch */
  uint32_t  Reserved20;          /*!< Reserved                     820h */
  uint32_t Reserved9;            /*!< Reserved                     824h */
  __IO uint32_t DVBUSDIS;        /*!< dev VBUS discharge Register  828h */
  __IO uint32_t DVBUSPULSE;      /*!< dev VBUS Pulse Register      82Ch */
  __IO uint32_t DTHRCTL;         /*!< dev threshold                830h */
  __IO uint32_t DIEPEMPMSK;      /*!< dev empty msk                834h */
  __IO uint32_t DEACHINT;        /*!< dedicated EP interrupt       838h */
  __IO uint32_t DEACHMSK;        /*!< dedicated EP msk             83Ch */  
  uint32_t Reserved40;           /*!< dedicated EP mask            840h */
  __IO uint32_t DINEP1MSK;       /*!< dedicated EP mask            844h */
  uint32_t  Reserved44[15];      /*!< Reserved                 844-87Ch */
  __IO uint32_t DOUTEP1MSK;      /*!< dedicated EP msk             884h */   
} USB_OTG_DeviceTypeDef;


/** 
  * @brief USB_OTG_IN_Endpoint-Specific_Register
  */
typedef struct 
{
  __IO uint32_t DIEPCTL;           /*!< dev IN Endpoint Control Reg    900h + (ep_num * 20h) + 00h */
  uint32_t Reserved04;             /*!< Reserved                       900h + (ep_num * 20h) + 04h */
  __IO uint32_t DIEPINT;           /*!< dev IN Endpoint Itr Reg        900h + (ep_num * 20h) + 08h */
  uint32_t Reserved0C;             /*!< Reserved                       900h + (ep_num * 20h) + 0Ch */
  __IO uint32_t DIEPTSIZ;          /*!< IN Endpoint Txfer Size         900h + (ep_num * 20h) + 10h */
  __IO uint32_t DIEPDMA;           /*!< IN Endpoint DMA Address Reg    900h + (ep_num * 20h) + 14h */
  __IO uint32_t DTXFSTS;           /*!< IN Endpoint Tx FIFO Status Reg 900h + (ep_num * 20h) + 18h */
  uint32_t Reserved18;             /*!< Reserved  900h+(ep_num*20h)+1Ch-900h+ (ep_num * 20h) + 1Ch */
} USB_OTG_INEndpointTypeDef;


/** 
  * @brief USB_OTG_OUT_Endpoint-Specific_Registers
  */
typedef struct 
{
  __IO uint32_t DOEPCTL;       /*!< dev OUT Endpoint Control Reg           B00h + (ep_num * 20h) + 00h */
  uint32_t Reserved04;         /*!< Reserved                               B00h + (ep_num * 20h) + 04h */
  __IO uint32_t DOEPINT;       /*!< dev OUT Endpoint Itr Reg               B00h + (ep_num * 20h) + 08h */
  uint32_t Reserved0C;         /*!< Reserved                               B00h + (ep_num * 20h) + 0Ch */
  __IO uint32_t DOEPTSIZ;      /*!< dev OUT Endpoint Txfer Size            B00h + (ep_num * 20h) + 10h */
  __IO uint32_t DOEPDMA;       /*!< dev OUT Endpoint DMA Address           B00h + (ep_num * 20h) + 14h */
  uint32_t Reserved18[2];      /*!< Reserved B00h + (ep_num * 20h) + 18h - B00h + (ep_num * 20h) + 1Ch */
} USB_OTG_OUTEndpointTypeDef;


/** 
  * @brief USB_OTG_Host_Mode_Register_Structures
  */
typedef struct 
{
  __IO uint32_t HCFG;             /*!< Host Configuration Register          400h */
  __IO uint32_t HFIR;             /*!< Host Frame Interval Register         404h */
  __IO uint32_t HFNUM;            /*!< Host Frame Nbr/Frame Remaining       408h */
  uint32_t Reserved40C;           /*!< Reserved                             40Ch */
  __IO uint32_t HPTXSTS;          /*!< Host Periodic Tx FIFO/ Queue Status  410h */
  __IO uint32_t HAINT;            /*!< Host All Channels Interrupt Register 414h */
  __IO uint32_t HAINTMSK;         /*!< Host All Channels Interrupt Mask     418h */
} USB_OTG_HostTypeDef;

/** 
  * @brief USB_OTG_Host_Channel_Specific_Registers
  */
typedef struct
{
  __IO uint32_t HCCHAR;           /*!< Host Channel Characteristics Register    500h */
  __IO uint32_t HCSPLT;           /*!< Host Channel Split Control Register      504h */
  __IO uint32_t HCINT;            /*!< Host Channel Interrupt Register          508h */
  __IO uint32_t HCINTMSK;         /*!< Host Channel Interrupt Mask Register     50Ch */
  __IO uint32_t HCTSIZ;           /*!< Host Channel Transfer Size Register      510h */
  __IO uint32_t HCDMA;            /*!< Host Channel DMA Address Register        514h */
  uint32_t Reserved[2];           /*!< Reserved                                      */
} USB_OTG_HostChannelTypeDef;
/**
  * @}
  */

  
/*!< USB registers base address */
#define USB_OTG0_HS_PERIPH_BASE               ((uint32_t )0x43000000)
#define USB_OTG1_HS_PERIPH_BASE               ((uint32_t )0x43100000)

#define USB_OTG_GLOBAL_BASE                  ((uint32_t )0x000)
#define USB_OTG_DEVICE_BASE                  ((uint32_t )0x800)
#define USB_OTG_IN_ENDPOINT_BASE             ((uint32_t )0x900)
#define USB_OTG_OUT_ENDPOINT_BASE            ((uint32_t )0xB00)
#define USB_OTG_EP_REG_SIZE                  ((uint32_t )0x20)
#define USB_OTG_HOST_BASE                    ((uint32_t )0x400)
#define USB_OTG_HOST_PORT_BASE               ((uint32_t )0x440)
#define USB_OTG_HOST_CHANNEL_BASE            ((uint32_t )0x500)
#define USB_OTG_HOST_CHANNEL_SIZE            ((uint32_t )0x20)
#define USB_OTG_PCGCCTL_BASE                 ((uint32_t )0xE00)
#define USB_OTG_FIFO_BASE                    ((uint32_t )0x1000)
#define USB_OTG_FIFO_SIZE                    ((uint32_t )0x1000)

/**
  * @}
  */
  
/** @addtogroup Peripheral_declaration
  * @{
  */  
#define USB_OTG0_HS          ((USB_OTG_GlobalTypeDef *) USB_OTG0_HS_PERIPH_BASE)
#define USB_OTG1_HS          ((USB_OTG_GlobalTypeDef *) USB_OTG1_HS_PERIPH_BASE)


/******************************************************************************/
/*                                                                            */
/*                                       USB_OTG                              */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for USB_OTG_GOTGCTL register  ********************/
#define USB_OTG_GOTGCTL_SRQSCS                  ((uint32_t)0x00000001)         /*!< Session request success */
#define USB_OTG_GOTGCTL_SRQ                     ((uint32_t)0x00000002)         /*!< Session request */
#define USB_OTG_GOTGCTL_VBVALOEN                ((uint32_t)0x00000004)         /*!< VBUS valid override enable */
#define USB_OTG_GOTGCTL_VBVALOVAL               ((uint32_t)0x00000008)         /*!< VBUS valid override value */
#define USB_OTG_GOTGCTL_AVALOEN                 ((uint32_t)0x00000010)         /*!< A-peripheral session valid override enable */
#define USB_OTG_GOTGCTL_AVALOVAL                ((uint32_t)0x00000020)         /*!< A-peripheral session valid override value */
#define USB_OTG_GOTGCTL_BVALOEN                 ((uint32_t)0x00000040)         /*!< B-peripheral session valid override enable */
#define USB_OTG_GOTGCTL_BVALOVAL                ((uint32_t)0x00000080)         /*!< B-peripheral session valid override value  */
#define USB_OTG_GOTGCTL_HNGSCS                  ((uint32_t)0x00000100)         /*!< Host set HNP enable */
#define USB_OTG_GOTGCTL_HNPRQ                   ((uint32_t)0x00000200)         /*!< HNP request */
#define USB_OTG_GOTGCTL_HSHNPEN                 ((uint32_t)0x00000400)         /*!< Host set HNP enable */
#define USB_OTG_GOTGCTL_DHNPEN                  ((uint32_t)0x00000800)         /*!< Device HNP enabled */
#define USB_OTG_GOTGCTL_EHEN                    ((uint32_t)0x00001000)         /*!< Embedded host enable */
#define USB_OTG_GOTGCTL_CIDSTS                  ((uint32_t)0x00010000)         /*!< Connector ID status */
#define USB_OTG_GOTGCTL_DBCT                    ((uint32_t)0x00020000)         /*!< Long/short debounce time */
#define USB_OTG_GOTGCTL_ASVLD                   ((uint32_t)0x00040000)         /*!< A-session valid  */
#define USB_OTG_GOTGCTL_BSESVLD                 ((uint32_t)0x00080000)         /*!< B-session valid */
#define USB_OTG_GOTGCTL_OTGVER                  ((uint32_t)0x00100000)         /*!< OTG version  */
#define USB_OTG_GOTGCTL_CURMOD                  ((uint32_t)0x00200000)         /*!< Current Mode  */

/********************  Bit definition for USB_OTG_HCFG register  ********************/
#define USB_OTG_HCFG_FSLSPCS                 ((uint32_t)0x00000003)            /*!< FS/LS PHY clock select  */
#define USB_OTG_HCFG_FSLSPCS_0               ((uint32_t)0x00000001)            /*!<Bit 0 */
#define USB_OTG_HCFG_FSLSPCS_1               ((uint32_t)0x00000002)            /*!<Bit 1 */
#define USB_OTG_HCFG_FSLSS                   ((uint32_t)0x00000004)            /*!< FS- and LS-only support */

/********************  Bit definition for USB_OTG_DCFG register  ********************/
#define USB_OTG_DCFG_DSPD                    ((uint32_t)0x00000003)            /*!< Device speed */
#define USB_OTG_DCFG_DSPD_0                  ((uint32_t)0x00000001)            /*!<Bit 0 */
#define USB_OTG_DCFG_DSPD_1                  ((uint32_t)0x00000002)            /*!<Bit 1 */
#define USB_OTG_DCFG_NZLSOHSK                ((uint32_t)0x00000004)            /*!< Nonzero-length status OUT handshake */

#define USB_OTG_DCFG_DAD                     ((uint32_t)0x000007F0)            /*!< Device address */
#define USB_OTG_DCFG_DAD_0                   ((uint32_t)0x00000010)            /*!<Bit 0 */
#define USB_OTG_DCFG_DAD_1                   ((uint32_t)0x00000020)            /*!<Bit 1 */
#define USB_OTG_DCFG_DAD_2                   ((uint32_t)0x00000040)            /*!<Bit 2 */
#define USB_OTG_DCFG_DAD_3                   ((uint32_t)0x00000080)            /*!<Bit 3 */
#define USB_OTG_DCFG_DAD_4                   ((uint32_t)0x00000100)            /*!<Bit 4 */
#define USB_OTG_DCFG_DAD_5                   ((uint32_t)0x00000200)            /*!<Bit 5 */
#define USB_OTG_DCFG_DAD_6                   ((uint32_t)0x00000400)            /*!<Bit 6 */

#define USB_OTG_DCFG_PFIVL                   ((uint32_t)0x00001800)            /*!< Periodic (micro)frame interval */
#define USB_OTG_DCFG_PFIVL_0                 ((uint32_t)0x00000800)            /*!<Bit 0 */
#define USB_OTG_DCFG_PFIVL_1                 ((uint32_t)0x00001000)            /*!<Bit 1 */

#define USB_OTG_DCFG_PERSCHIVL               ((uint32_t)0x03000000)            /*!< Periodic scheduling interval */
#define USB_OTG_DCFG_PERSCHIVL_0             ((uint32_t)0x01000000)            /*!<Bit 0 */
#define USB_OTG_DCFG_PERSCHIVL_1             ((uint32_t)0x02000000)            /*!<Bit 1 */

/********************  Bit definition for USB_OTG_PCGCR register  ********************/
#define USB_OTG_PCGCR_STPPCLK                 ((uint32_t)0x00000001)            /*!< Stop PHY clock */
#define USB_OTG_PCGCR_GATEHCLK                ((uint32_t)0x00000002)            /*!< Gate HCLK */
#define USB_OTG_PCGCR_PHYSUSP                 ((uint32_t)0x00000010)            /*!< PHY suspended */

/********************  Bit definition for USB_OTG_GOTGINT register  ********************/
#define USB_OTG_GOTGINT_SEDET                   ((uint32_t)0x00000004)            /*!< Session end detected                   */
#define USB_OTG_GOTGINT_SRSSCHG                 ((uint32_t)0x00000100)            /*!< Session request success status change  */
#define USB_OTG_GOTGINT_HNSSCHG                 ((uint32_t)0x00000200)            /*!< Host negotiation success status change */
#define USB_OTG_GOTGINT_HNGDET                  ((uint32_t)0x00020000)            /*!< Host negotiation detected              */
#define USB_OTG_GOTGINT_ADTOCHG                 ((uint32_t)0x00040000)            /*!< A-device timeout change                */
#define USB_OTG_GOTGINT_DBCDNE                  ((uint32_t)0x00080000)            /*!< Debounce done                          */
#define USB_OTG_GOTGINT_IDCHNG                  ((uint32_t)0x00100000)            /*!< Change in ID pin input value           */

/********************  Bit definition for USB_OTG_DCTL register  ********************/
#define USB_OTG_DCTL_RWUSIG                  ((uint32_t)0x00000001)            /*!< Remote wakeup signaling */
#define USB_OTG_DCTL_SDIS                    ((uint32_t)0x00000002)            /*!< Soft disconnect         */
#define USB_OTG_DCTL_GINSTS                  ((uint32_t)0x00000004)            /*!< Global IN NAK status    */
#define USB_OTG_DCTL_GONSTS                  ((uint32_t)0x00000008)            /*!< Global OUT NAK status   */

#define USB_OTG_DCTL_TCTL                    ((uint32_t)0x00000070)            /*!< Test control */
#define USB_OTG_DCTL_TCTL_0                  ((uint32_t)0x00000010)            /*!<Bit 0 */
#define USB_OTG_DCTL_TCTL_1                  ((uint32_t)0x00000020)            /*!<Bit 1 */
#define USB_OTG_DCTL_TCTL_2                  ((uint32_t)0x00000040)            /*!<Bit 2 */
#define USB_OTG_DCTL_SGINAK                  ((uint32_t)0x00000080)            /*!< Set global IN NAK         */
#define USB_OTG_DCTL_CGINAK                  ((uint32_t)0x00000100)            /*!< Clear global IN NAK       */
#define USB_OTG_DCTL_SGONAK                  ((uint32_t)0x00000200)            /*!< Set global OUT NAK        */
#define USB_OTG_DCTL_CGONAK                  ((uint32_t)0x00000400)            /*!< Clear global OUT NAK      */
#define USB_OTG_DCTL_POPRGDNE                ((uint32_t)0x00000800)            /*!< Power-on programming done */

/********************  Bit definition for USB_OTG_HFIR register  ********************/
#define USB_OTG_HFIR_FRIVL                   ((uint32_t)0x0000FFFF)            /*!< Frame interval */

/********************  Bit definition for USB_OTG_HFNUM register  ********************/
#define USB_OTG_HFNUM_FRNUM                   ((uint32_t)0x0000FFFF)            /*!< Frame number         */
#define USB_OTG_HFNUM_FTREM                   ((uint32_t)0xFFFF0000)            /*!< Frame time remaining */

/********************  Bit definition for USB_OTG_DSTS register  ********************/
#define USB_OTG_DSTS_SUSPSTS                 ((uint32_t)0x00000001)            /*!< Suspend status   */

#define USB_OTG_DSTS_ENUMSPD                 ((uint32_t)0x00000006)            /*!< Enumerated speed */
#define USB_OTG_DSTS_ENUMSPD_0               ((uint32_t)0x00000002)            /*!<Bit 0 */
#define USB_OTG_DSTS_ENUMSPD_1               ((uint32_t)0x00000004)            /*!<Bit 1 */
#define USB_OTG_DSTS_EERR                    ((uint32_t)0x00000008)            /*!< Erratic error     */
#define USB_OTG_DSTS_FNSOF                   ((uint32_t)0x003FFF00)            /*!< Frame number of the received SOF */

/********************  Bit definition for USB_OTG_GAHBCFG register  ********************/
#define USB_OTG_GAHBCFG_GINT                    ((uint32_t)0x00000001)            /*!< Global interrupt mask */
#define USB_OTG_GAHBCFG_HBSTLEN                 ((uint32_t)0x0000001E)            /*!< Burst length/type */
#define USB_OTG_GAHBCFG_HBSTLEN_0               ((uint32_t)0x00000002)            /*!<Bit 0 */
#define USB_OTG_GAHBCFG_HBSTLEN_1               ((uint32_t)0x00000004)            /*!<Bit 1 */
#define USB_OTG_GAHBCFG_HBSTLEN_2               ((uint32_t)0x00000008)            /*!<Bit 2 */
#define USB_OTG_GAHBCFG_HBSTLEN_3               ((uint32_t)0x00000010)            /*!<Bit 3 */
#define USB_OTG_GAHBCFG_DMAEN                   ((uint32_t)0x00000020)            /*!< DMA enable */
#define USB_OTG_GAHBCFG_TXFELVL                 ((uint32_t)0x00000080)            /*!< TxFIFO empty level */
#define USB_OTG_GAHBCFG_PTXFELVL                ((uint32_t)0x00000100)            /*!< Periodic TxFIFO empty level */

/********************  Bit definition for USB_OTG_GUSBCFG register  ********************/
#define USB_OTG_GUSBCFG_TOCAL                   ((uint32_t)0x00000007)            /*!< FS timeout calibration */
#define USB_OTG_GUSBCFG_TOCAL_0                 ((uint32_t)0x00000001)            /*!<Bit 0 */
#define USB_OTG_GUSBCFG_TOCAL_1                 ((uint32_t)0x00000002)            /*!<Bit 1 */
#define USB_OTG_GUSBCFG_TOCAL_2                 ((uint32_t)0x00000004)            /*!<Bit 2 */
#define USB_OTG_GUSBCFG_PHYSEL                  ((uint32_t)0x00000040)            /*!< USB 2.0 high-speed ULPI PHY or USB 1.1 full-speed serial transceiver select */
#define USB_OTG_GUSBCFG_SRPCAP                  ((uint32_t)0x00000100)            /*!< SRP-capable */
#define USB_OTG_GUSBCFG_HNPCAP                  ((uint32_t)0x00000200)            /*!< HNP-capable */
#define USB_OTG_GUSBCFG_TRDT                    ((uint32_t)0x00003C00)            /*!< USB turnaround time */
#define USB_OTG_GUSBCFG_TRDT_0                  ((uint32_t)0x00000400)            /*!<Bit 0 */
#define USB_OTG_GUSBCFG_TRDT_1                  ((uint32_t)0x00000800)            /*!<Bit 1 */
#define USB_OTG_GUSBCFG_TRDT_2                  ((uint32_t)0x00001000)            /*!<Bit 2 */
#define USB_OTG_GUSBCFG_TRDT_3                  ((uint32_t)0x00002000)            /*!<Bit 3 */
#define USB_OTG_GUSBCFG_PHYLPCS                 ((uint32_t)0x00008000)            /*!< PHY Low-power clock select */
#define USB_OTG_GUSBCFG_ULPIFSLS                ((uint32_t)0x00020000)            /*!< ULPI FS/LS select               */
#define USB_OTG_GUSBCFG_ULPIAR                  ((uint32_t)0x00040000)            /*!< ULPI Auto-resume                */
#define USB_OTG_GUSBCFG_ULPICSM                 ((uint32_t)0x00080000)            /*!< ULPI Clock SuspendM             */
#define USB_OTG_GUSBCFG_ULPIEVBUSD              ((uint32_t)0x00100000)            /*!< ULPI External VBUS Drive        */
#define USB_OTG_GUSBCFG_ULPIEVBUSI              ((uint32_t)0x00200000)            /*!< ULPI external VBUS indicator    */
#define USB_OTG_GUSBCFG_TSDPS                   ((uint32_t)0x00400000)            /*!< TermSel DLine pulsing selection */
#define USB_OTG_GUSBCFG_PCCI                    ((uint32_t)0x00800000)            /*!< Indicator complement            */
#define USB_OTG_GUSBCFG_PTCI                    ((uint32_t)0x01000000)            /*!< Indicator pass through          */
#define USB_OTG_GUSBCFG_ULPIIPD                 ((uint32_t)0x02000000)            /*!< ULPI interface protect disable  */
#define USB_OTG_GUSBCFG_FHMOD                   ((uint32_t)0x20000000)            /*!< Forced host mode                */
#define USB_OTG_GUSBCFG_FDMOD                   ((uint32_t)0x40000000)            /*!< Forced peripheral mode          */
#define USB_OTG_GUSBCFG_CTXPKT                  ((uint32_t)0x80000000)            /*!< Corrupt Tx packet               */
#define USB_OTG_GUSBCFG_UTMISEL                 ((uint32_t)0x00000010)            /*UTMI ULPI sel*/
#define USB_OTG_GUSBCFG_PHYIF                   ((uint32_t)0x00000008)            /*PHY Interface width*/

/********************  Bit definition for USB_OTG_GRSTCTL register  ********************/
#define USB_OTG_GRSTCTL_CSRST                   ((uint32_t)0x00000001)            /*!< Core soft reset          */
#define USB_OTG_GRSTCTL_HSRST                   ((uint32_t)0x00000002)            /*!< HCLK soft reset          */
#define USB_OTG_GRSTCTL_FCRST                   ((uint32_t)0x00000004)            /*!< Host frame counter reset */
#define USB_OTG_GRSTCTL_RXFFLSH                 ((uint32_t)0x00000010)            /*!< RxFIFO flush             */
#define USB_OTG_GRSTCTL_TXFFLSH                 ((uint32_t)0x00000020)            /*!< TxFIFO flush             */
#define USB_OTG_GRSTCTL_TXFNUM                  ((uint32_t)0x000007C0)            /*!< TxFIFO number */
#define USB_OTG_GRSTCTL_TXFNUM_0                ((uint32_t)0x00000040)            /*!<Bit 0 */
#define USB_OTG_GRSTCTL_TXFNUM_1                ((uint32_t)0x00000080)            /*!<Bit 1 */
#define USB_OTG_GRSTCTL_TXFNUM_2                ((uint32_t)0x00000100)            /*!<Bit 2 */
#define USB_OTG_GRSTCTL_TXFNUM_3                ((uint32_t)0x00000200)            /*!<Bit 3 */
#define USB_OTG_GRSTCTL_TXFNUM_4                ((uint32_t)0x00000400)            /*!<Bit 4 */
#define USB_OTG_GRSTCTL_DMAREQ                  ((uint32_t)0x40000000)            /*!< DMA request signal */
#define USB_OTG_GRSTCTL_AHBIDL                  ((uint32_t)0x80000000)            /*!< AHB master idle */

/********************  Bit definition for USB_OTG_DIEPMSK register  ********************/
#define USB_OTG_DIEPMSK_XFRCM                   ((uint32_t)0x00000001)            /*!< Transfer completed interrupt mask                 */
#define USB_OTG_DIEPMSK_EPDM                    ((uint32_t)0x00000002)            /*!< Endpoint disabled interrupt mask                  */
#define USB_OTG_DIEPMSK_TOM                     ((uint32_t)0x00000008)            /*!< Timeout condition mask (nonisochronous endpoints) */
#define USB_OTG_DIEPMSK_ITTXFEMSK               ((uint32_t)0x00000010)            /*!< IN token received when TxFIFO empty mask          */
#define USB_OTG_DIEPMSK_INEPNMM                 ((uint32_t)0x00000020)            /*!< IN token received with EP mismatch mask           */
#define USB_OTG_DIEPMSK_INEPNEM                 ((uint32_t)0x00000040)            /*!< IN endpoint NAK effective mask                    */
#define USB_OTG_DIEPMSK_TXFURM                  ((uint32_t)0x00000100)            /*!< FIFO underrun mask                                */
#define USB_OTG_DIEPMSK_BIM                     ((uint32_t)0x00000200)            /*!< BNA interrupt mask                                */

/********************  Bit definition for USB_OTG_HPTXSTS register  ********************/
#define USB_OTG_HPTXSTS_PTXFSAVL                ((uint32_t)0x0000FFFF)            /*!< Periodic transmit data FIFO space available     */
#define USB_OTG_HPTXSTS_PTXQSAV                 ((uint32_t)0x00FF0000)            /*!< Periodic transmit request queue space available */
#define USB_OTG_HPTXSTS_PTXQSAV_0               ((uint32_t)0x00010000)            /*!<Bit 0 */
#define USB_OTG_HPTXSTS_PTXQSAV_1               ((uint32_t)0x00020000)            /*!<Bit 1 */
#define USB_OTG_HPTXSTS_PTXQSAV_2               ((uint32_t)0x00040000)            /*!<Bit 2 */
#define USB_OTG_HPTXSTS_PTXQSAV_3               ((uint32_t)0x00080000)            /*!<Bit 3 */
#define USB_OTG_HPTXSTS_PTXQSAV_4               ((uint32_t)0x00100000)            /*!<Bit 4 */
#define USB_OTG_HPTXSTS_PTXQSAV_5               ((uint32_t)0x00200000)            /*!<Bit 5 */
#define USB_OTG_HPTXSTS_PTXQSAV_6               ((uint32_t)0x00400000)            /*!<Bit 6 */
#define USB_OTG_HPTXSTS_PTXQSAV_7               ((uint32_t)0x00800000)            /*!<Bit 7 */

#define USB_OTG_HPTXSTS_PTXQTOP                 ((uint32_t)0xFF000000)            /*!< Top of the periodic transmit request queue */
#define USB_OTG_HPTXSTS_PTXQTOP_0               ((uint32_t)0x01000000)            /*!<Bit 0 */
#define USB_OTG_HPTXSTS_PTXQTOP_1               ((uint32_t)0x02000000)            /*!<Bit 1 */
#define USB_OTG_HPTXSTS_PTXQTOP_2               ((uint32_t)0x04000000)            /*!<Bit 2 */
#define USB_OTG_HPTXSTS_PTXQTOP_3               ((uint32_t)0x08000000)            /*!<Bit 3 */
#define USB_OTG_HPTXSTS_PTXQTOP_4               ((uint32_t)0x10000000)            /*!<Bit 4 */
#define USB_OTG_HPTXSTS_PTXQTOP_5               ((uint32_t)0x20000000)            /*!<Bit 5 */
#define USB_OTG_HPTXSTS_PTXQTOP_6               ((uint32_t)0x40000000)            /*!<Bit 6 */
#define USB_OTG_HPTXSTS_PTXQTOP_7               ((uint32_t)0x80000000)            /*!<Bit 7 */

/********************  Bit definition for USB_OTG_HAINT register  ********************/
#define USB_OTG_HAINT_HAINT                   ((uint32_t)0x0000FFFF)            /*!< Channel interrupts */

/********************  Bit definition for USB_OTG_DOEPMSK register  ********************/
#define USB_OTG_DOEPMSK_XFRCM                   ((uint32_t)0x00000001)            /*!< Transfer completed interrupt mask */
#define USB_OTG_DOEPMSK_EPDM                    ((uint32_t)0x00000002)            /*!< Endpoint disabled interrupt mask               */
#define USB_OTG_DOEPMSK_STUPM                   ((uint32_t)0x00000008)            /*!< SETUP phase done mask                          */
#define USB_OTG_DOEPMSK_OTEPDM                  ((uint32_t)0x00000010)            /*!< OUT token received when endpoint disabled mask */
#define USB_OTG_DOEPMSK_B2BSTUP                 ((uint32_t)0x00000040)            /*!< Back-to-back SETUP packets received mask       */
#define USB_OTG_DOEPMSK_OPEM                    ((uint32_t)0x00000100)            /*!< OUT packet error mask                          */
#define USB_OTG_DOEPMSK_BOIM                    ((uint32_t)0x00000200)            /*!< BNA interrupt mask                             */

/********************  Bit definition for USB_OTG_GINTSTS register  ********************/
#define USB_OTG_GINTSTS_CMOD                    ((uint32_t)0x00000001)            /*!< Current mode of operation                      */
#define USB_OTG_GINTSTS_MMIS                    ((uint32_t)0x00000002)            /*!< Mode mismatch interrupt                        */
#define USB_OTG_GINTSTS_OTGINT                  ((uint32_t)0x00000004)            /*!< OTG interrupt                                  */
#define USB_OTG_GINTSTS_SOF                     ((uint32_t)0x00000008)            /*!< Start of frame                                 */
#define USB_OTG_GINTSTS_RXFLVL                  ((uint32_t)0x00000010)            /*!< RxFIFO nonempty                                */
#define USB_OTG_GINTSTS_NPTXFE                  ((uint32_t)0x00000020)            /*!< Nonperiodic TxFIFO empty                       */
#define USB_OTG_GINTSTS_GINAKEFF                ((uint32_t)0x00000040)            /*!< Global IN nonperiodic NAK effective            */
#define USB_OTG_GINTSTS_BOUTNAKEFF              ((uint32_t)0x00000080)            /*!< Global OUT NAK effective                       */
#define USB_OTG_GINTSTS_ESUSP                   ((uint32_t)0x00000400)            /*!< Early suspend                                  */
#define USB_OTG_GINTSTS_USBSUSP                 ((uint32_t)0x00000800)            /*!< USB suspend                                    */
#define USB_OTG_GINTSTS_USBRST                  ((uint32_t)0x00001000)            /*!< USB reset                                      */
#define USB_OTG_GINTSTS_ENUMDNE                 ((uint32_t)0x00002000)            /*!< Enumeration done                               */
#define USB_OTG_GINTSTS_ISOODRP                 ((uint32_t)0x00004000)            /*!< Isochronous OUT packet dropped interrupt       */
#define USB_OTG_GINTSTS_EOPF                    ((uint32_t)0x00008000)            /*!< End of periodic frame interrupt                */
#define USB_OTG_GINTSTS_IEPINT                  ((uint32_t)0x00040000)            /*!< IN endpoint interrupt                          */
#define USB_OTG_GINTSTS_OEPINT                  ((uint32_t)0x00080000)            /*!< OUT endpoint interrupt                         */
#define USB_OTG_GINTSTS_IISOIXFR                ((uint32_t)0x00100000)            /*!< Incomplete isochronous IN transfer             */
#define USB_OTG_GINTSTS_PXFR_INCOMPISOOUT       ((uint32_t)0x00200000)            /*!< Incomplete periodic transfer                   */
#define USB_OTG_GINTSTS_DATAFSUSP               ((uint32_t)0x00400000)            /*!< Data fetch suspended                           */
#define USB_OTG_GINTSTS_RSTDET                  ((uint32_t)0x00800000)            /*!< Reset detected interrupt                       */
#define USB_OTG_GINTSTS_HPRTINT                 ((uint32_t)0x01000000)            /*!< Host port interrupt                            */
#define USB_OTG_GINTSTS_HCINT                   ((uint32_t)0x02000000)            /*!< Host channels interrupt                        */
#define USB_OTG_GINTSTS_PTXFE                   ((uint32_t)0x04000000)            /*!< Periodic TxFIFO empty                          */
#define USB_OTG_GINTSTS_LPMINT                  ((uint32_t)0x08000000)            /*!< LPM interrupt                                  */
#define USB_OTG_GINTSTS_CIDSCHG                 ((uint32_t)0x10000000)            /*!< Connector ID status change                     */
#define USB_OTG_GINTSTS_DISCINT                 ((uint32_t)0x20000000)            /*!< Disconnect detected interrupt                  */
#define USB_OTG_GINTSTS_SRQINT                  ((uint32_t)0x40000000)            /*!< Session request/new session detected interrupt */
#define USB_OTG_GINTSTS_WKUINT                  ((uint32_t)0x80000000)            /*!< Resume/remote wakeup detected interrupt        */

/********************  Bit definition for USB_OTG_GINTMSK register  ********************/
#define USB_OTG_GINTMSK_MMISM                   ((uint32_t)0x00000002)            /*!< Mode mismatch interrupt mask                        */
#define USB_OTG_GINTMSK_OTGINT                  ((uint32_t)0x00000004)            /*!< OTG interrupt mask                                  */
#define USB_OTG_GINTMSK_SOFM                    ((uint32_t)0x00000008)            /*!< Start of frame mask                                 */
#define USB_OTG_GINTMSK_RXFLVLM                 ((uint32_t)0x00000010)            /*!< Receive FIFO nonempty mask                          */
#define USB_OTG_GINTMSK_NPTXFEM                 ((uint32_t)0x00000020)            /*!< Nonperiodic TxFIFO empty mask                       */
#define USB_OTG_GINTMSK_GINAKEFFM               ((uint32_t)0x00000040)            /*!< Global nonperiodic IN NAK effective mask            */
#define USB_OTG_GINTMSK_GONAKEFFM               ((uint32_t)0x00000080)            /*!< Global OUT NAK effective mask                       */
#define USB_OTG_GINTMSK_ESUSPM                  ((uint32_t)0x00000400)            /*!< Early suspend mask                                  */
#define USB_OTG_GINTMSK_USBSUSPM                ((uint32_t)0x00000800)            /*!< USB suspend mask                                    */
#define USB_OTG_GINTMSK_USBRST                  ((uint32_t)0x00001000)            /*!< USB reset mask                                      */
#define USB_OTG_GINTMSK_ENUMDNEM                ((uint32_t)0x00002000)            /*!< Enumeration done mask                               */
#define USB_OTG_GINTMSK_ISOODRPM                ((uint32_t)0x00004000)            /*!< Isochronous OUT packet dropped interrupt mask       */
#define USB_OTG_GINTMSK_EOPFM                   ((uint32_t)0x00008000)            /*!< End of periodic frame interrupt mask                */
#define USB_OTG_GINTMSK_EPMISM                  ((uint32_t)0x00020000)            /*!< Endpoint mismatch interrupt mask                    */
#define USB_OTG_GINTMSK_IEPINT                  ((uint32_t)0x00040000)            /*!< IN endpoints interrupt mask                         */
#define USB_OTG_GINTMSK_OEPINT                  ((uint32_t)0x00080000)            /*!< OUT endpoints interrupt mask                        */
#define USB_OTG_GINTMSK_IISOIXFRM               ((uint32_t)0x00100000)            /*!< Incomplete isochronous IN transfer mask             */
#define USB_OTG_GINTMSK_PXFRM_IISOOXFRM         ((uint32_t)0x00200000)            /*!< Incomplete periodic transfer mask                   */
#define USB_OTG_GINTMSK_FSUSPM                  ((uint32_t)0x00400000)            /*!< Data fetch suspended mask                           */
#define USB_OTG_GINTMSK_RSTDEM                  ((uint32_t)0x00800000)            /*!< Reset detected interrupt mask                      */
#define USB_OTG_GINTMSK_PRTIM                   ((uint32_t)0x01000000)            /*!< Host port interrupt mask                            */
#define USB_OTG_GINTMSK_HCIM                    ((uint32_t)0x02000000)            /*!< Host channels interrupt mask                        */
#define USB_OTG_GINTMSK_PTXFEM                  ((uint32_t)0x04000000)            /*!< Periodic TxFIFO empty mask                          */
#define USB_OTG_GINTMSK_LPMINTM                 ((uint32_t)0x08000000)            /*!< LPM interrupt Mask                                  */
#define USB_OTG_GINTMSK_CIDSCHGM                ((uint32_t)0x10000000)            /*!< Connector ID status change mask                     */
#define USB_OTG_GINTMSK_DISCINT                 ((uint32_t)0x20000000)            /*!< Disconnect detected interrupt mask                  */
#define USB_OTG_GINTMSK_SRQIM                   ((uint32_t)0x40000000)            /*!< Session request/new session detected interrupt mask */
#define USB_OTG_GINTMSK_WUIM                    ((uint32_t)0x80000000)            /*!< Resume/remote wakeup detected interrupt mask        */

/********************  Bit definition for USB_OTG_DAINT register  ********************/
#define USB_OTG_DAINT_IEPINT                  ((uint32_t)0x0000FFFF)            /*!< IN endpoint interrupt bits  */
#define USB_OTG_DAINT_OEPINT                  ((uint32_t)0xFFFF0000)            /*!< OUT endpoint interrupt bits */

/********************  Bit definition for USB_OTG_HAINTMSK register  ********************/
#define USB_OTG_HAINTMSK_HAINTM                  ((uint32_t)0x0000FFFF)            /*!< Channel interrupt mask */

/********************  Bit definition for USB_OTG_GRXSTSP register  ********************/
#define USB_OTG_GRXSTSP_EPNUM                    ((uint32_t)0x0000000F)            /*!< IN EP interrupt mask bits  */
#define USB_OTG_GRXSTSP_BCNT                     ((uint32_t)0x00007FF0)            /*!< OUT EP interrupt mask bits */
#define USB_OTG_GRXSTSP_DPID                     ((uint32_t)0x00018000)            /*!< OUT EP interrupt mask bits */
#define USB_OTG_GRXSTSP_PKTSTS                   ((uint32_t)0x001E0000)            /*!< OUT EP interrupt mask bits */

/********************  Bit definition for USB_OTG_DAINTMSK register  ********************/
#define USB_OTG_DAINTMSK_IEPM                    ((uint32_t)0x0000FFFF)            /*!< IN EP interrupt mask bits */
#define USB_OTG_DAINTMSK_OEPM                    ((uint32_t)0xFFFF0000)            /*!< OUT EP interrupt mask bits */

/********************  Bit definition for OTG register  ********************/

#define USB_OTG_CHNUM                   ((uint32_t)0x0000000F)            /*!< Channel number */
#define USB_OTG_CHNUM_0                 ((uint32_t)0x00000001)            /*!<Bit 0 */
#define USB_OTG_CHNUM_1                 ((uint32_t)0x00000002)            /*!<Bit 1 */
#define USB_OTG_CHNUM_2                 ((uint32_t)0x00000004)            /*!<Bit 2 */
#define USB_OTG_CHNUM_3                 ((uint32_t)0x00000008)            /*!<Bit 3 */
#define USB_OTG_BCNT                    ((uint32_t)0x00007FF0)            /*!< Byte count */

#define USB_OTG_DPID                    ((uint32_t)0x00018000)            /*!< Data PID */
#define USB_OTG_DPID_0                  ((uint32_t)0x00008000)            /*!<Bit 0 */
#define USB_OTG_DPID_1                  ((uint32_t)0x00010000)            /*!<Bit 1 */

#define USB_OTG_PKTSTS                  ((uint32_t)0x001E0000)            /*!< Packet status */
#define USB_OTG_PKTSTS_0                ((uint32_t)0x00020000)            /*!<Bit 0 */
#define USB_OTG_PKTSTS_1                ((uint32_t)0x00040000)            /*!<Bit 1 */
#define USB_OTG_PKTSTS_2                ((uint32_t)0x00080000)            /*!<Bit 2 */
#define USB_OTG_PKTSTS_3                ((uint32_t)0x00100000)            /*!<Bit 3 */

#define USB_OTG_EPNUM                   ((uint32_t)0x0000000F)            /*!< Endpoint number */
#define USB_OTG_EPNUM_0                 ((uint32_t)0x00000001)            /*!<Bit 0 */
#define USB_OTG_EPNUM_1                 ((uint32_t)0x00000002)            /*!<Bit 1 */
#define USB_OTG_EPNUM_2                 ((uint32_t)0x00000004)            /*!<Bit 2 */
#define USB_OTG_EPNUM_3                 ((uint32_t)0x00000008)            /*!<Bit 3 */

#define USB_OTG_FRMNUM                  ((uint32_t)0x01E00000)            /*!< Frame number */
#define USB_OTG_FRMNUM_0                ((uint32_t)0x00200000)            /*!<Bit 0 */
#define USB_OTG_FRMNUM_1                ((uint32_t)0x00400000)            /*!<Bit 1 */
#define USB_OTG_FRMNUM_2                ((uint32_t)0x00800000)            /*!<Bit 2 */
#define USB_OTG_FRMNUM_3                ((uint32_t)0x01000000)            /*!<Bit 3 */

/********************  Bit definition for OTG register  ********************/

#define USB_OTG_CHNUM                   ((uint32_t)0x0000000F)            /*!< Channel number */
#define USB_OTG_CHNUM_0                 ((uint32_t)0x00000001)            /*!<Bit 0 */
#define USB_OTG_CHNUM_1                 ((uint32_t)0x00000002)            /*!<Bit 1 */
#define USB_OTG_CHNUM_2                 ((uint32_t)0x00000004)            /*!<Bit 2 */
#define USB_OTG_CHNUM_3                 ((uint32_t)0x00000008)            /*!<Bit 3 */
#define USB_OTG_BCNT                    ((uint32_t)0x00007FF0)            /*!< Byte count */

#define USB_OTG_DPID                    ((uint32_t)0x00018000)            /*!< Data PID */
#define USB_OTG_DPID_0                  ((uint32_t)0x00008000)            /*!<Bit 0 */
#define USB_OTG_DPID_1                  ((uint32_t)0x00010000)            /*!<Bit 1 */

#define USB_OTG_PKTSTS                  ((uint32_t)0x001E0000)            /*!< Packet status */
#define USB_OTG_PKTSTS_0                ((uint32_t)0x00020000)            /*!<Bit 0 */
#define USB_OTG_PKTSTS_1                ((uint32_t)0x00040000)            /*!<Bit 1 */
#define USB_OTG_PKTSTS_2                ((uint32_t)0x00080000)            /*!<Bit 2 */
#define USB_OTG_PKTSTS_3                ((uint32_t)0x00100000)            /*!<Bit 3 */

#define USB_OTG_EPNUM                   ((uint32_t)0x0000000F)            /*!< Endpoint number */
#define USB_OTG_EPNUM_0                 ((uint32_t)0x00000001)            /*!<Bit 0 */
#define USB_OTG_EPNUM_1                 ((uint32_t)0x00000002)            /*!<Bit 1 */
#define USB_OTG_EPNUM_2                 ((uint32_t)0x00000004)            /*!<Bit 2 */
#define USB_OTG_EPNUM_3                 ((uint32_t)0x00000008)            /*!<Bit 3 */

#define USB_OTG_FRMNUM                  ((uint32_t)0x01E00000)            /*!< Frame number */
#define USB_OTG_FRMNUM_0                ((uint32_t)0x00200000)            /*!<Bit 0 */
#define USB_OTG_FRMNUM_1                ((uint32_t)0x00400000)            /*!<Bit 1 */
#define USB_OTG_FRMNUM_2                ((uint32_t)0x00800000)            /*!<Bit 2 */
#define USB_OTG_FRMNUM_3                ((uint32_t)0x01000000)            /*!<Bit 3 */

/********************  Bit definition for USB_OTG_GRXFSIZ register  ********************/
#define USB_OTG_GRXFSIZ_RXFD            ((uint32_t)0x0000FFFF)            /*!< RxFIFO depth */

/********************  Bit definition for USB_OTG_DVBUSDIS register  ********************/
#define USB_OTG_DVBUSDIS_VBUSDT         ((uint32_t)0x0000FFFF)            /*!< Device VBUS discharge time */

/********************  Bit definition for OTG register  ********************/
#define USB_OTG_NPTXFSA                 ((uint32_t)0x0000FFFF)            /*!< Nonperiodic transmit RAM start address */
#define USB_OTG_NPTXFD                  ((uint32_t)0xFFFF0000)            /*!< Nonperiodic TxFIFO depth               */
#define USB_OTG_TX0FSA                  ((uint32_t)0x0000FFFF)            /*!< Endpoint 0 transmit RAM start address  */
#define USB_OTG_TX0FD                   ((uint32_t)0xFFFF0000)            /*!< Endpoint 0 TxFIFO depth                */

/********************  Bit definition for USB_OTG_DVBUSPULSE register  ********************/
#define USB_OTG_DVBUSPULSE_DVBUSP                  ((uint32_t)0x00000FFF)            /*!< Device VBUS pulsing time */

/********************  Bit definition for USB_OTG_GNPTXSTS register  ********************/
#define USB_OTG_GNPTXSTS_NPTXFSAV                ((uint32_t)0x0000FFFF)            /*!< Nonperiodic TxFIFO space available */

#define USB_OTG_GNPTXSTS_NPTQXSAV                ((uint32_t)0x00FF0000)            /*!< Nonperiodic transmit request queue space available */
#define USB_OTG_GNPTXSTS_NPTQXSAV_0              ((uint32_t)0x00010000)            /*!<Bit 0 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_1              ((uint32_t)0x00020000)            /*!<Bit 1 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_2              ((uint32_t)0x00040000)            /*!<Bit 2 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_3              ((uint32_t)0x00080000)            /*!<Bit 3 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_4              ((uint32_t)0x00100000)            /*!<Bit 4 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_5              ((uint32_t)0x00200000)            /*!<Bit 5 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_6              ((uint32_t)0x00400000)            /*!<Bit 6 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_7              ((uint32_t)0x00800000)            /*!<Bit 7 */

#define USB_OTG_GNPTXSTS_NPTXQTOP                ((uint32_t)0x7F000000)            /*!< Top of the nonperiodic transmit request queue */
#define USB_OTG_GNPTXSTS_NPTXQTOP_0              ((uint32_t)0x01000000)            /*!<Bit 0 */
#define USB_OTG_GNPTXSTS_NPTXQTOP_1              ((uint32_t)0x02000000)            /*!<Bit 1 */
#define USB_OTG_GNPTXSTS_NPTXQTOP_2              ((uint32_t)0x04000000)            /*!<Bit 2 */
#define USB_OTG_GNPTXSTS_NPTXQTOP_3              ((uint32_t)0x08000000)            /*!<Bit 3 */
#define USB_OTG_GNPTXSTS_NPTXQTOP_4              ((uint32_t)0x10000000)            /*!<Bit 4 */
#define USB_OTG_GNPTXSTS_NPTXQTOP_5              ((uint32_t)0x20000000)            /*!<Bit 5 */
#define USB_OTG_GNPTXSTS_NPTXQTOP_6              ((uint32_t)0x40000000)            /*!<Bit 6 */

/********************  Bit definition for USB_OTG_DTHRCTL register  ********************/
#define USB_OTG_DTHRCTL_NONISOTHREN             ((uint32_t)0x00000001)            /*!< Nonisochronous IN endpoints threshold enable */
#define USB_OTG_DTHRCTL_ISOTHREN                ((uint32_t)0x00000002)            /*!< ISO IN endpoint threshold enable */

#define USB_OTG_DTHRCTL_TXTHRLEN                ((uint32_t)0x000007FC)            /*!< Transmit threshold length */
#define USB_OTG_DTHRCTL_TXTHRLEN_0              ((uint32_t)0x00000004)            /*!<Bit 0 */
#define USB_OTG_DTHRCTL_TXTHRLEN_1              ((uint32_t)0x00000008)            /*!<Bit 1 */
#define USB_OTG_DTHRCTL_TXTHRLEN_2              ((uint32_t)0x00000010)            /*!<Bit 2 */
#define USB_OTG_DTHRCTL_TXTHRLEN_3              ((uint32_t)0x00000020)            /*!<Bit 3 */
#define USB_OTG_DTHRCTL_TXTHRLEN_4              ((uint32_t)0x00000040)            /*!<Bit 4 */
#define USB_OTG_DTHRCTL_TXTHRLEN_5              ((uint32_t)0x00000080)            /*!<Bit 5 */
#define USB_OTG_DTHRCTL_TXTHRLEN_6              ((uint32_t)0x00000100)            /*!<Bit 6 */
#define USB_OTG_DTHRCTL_TXTHRLEN_7              ((uint32_t)0x00000200)            /*!<Bit 7 */
#define USB_OTG_DTHRCTL_TXTHRLEN_8              ((uint32_t)0x00000400)            /*!<Bit 8 */
#define USB_OTG_DTHRCTL_RXTHREN                 ((uint32_t)0x00010000)            /*!< Receive threshold enable */

#define USB_OTG_DTHRCTL_RXTHRLEN                ((uint32_t)0x03FE0000)            /*!< Receive threshold length */
#define USB_OTG_DTHRCTL_RXTHRLEN_0              ((uint32_t)0x00020000)            /*!<Bit 0 */
#define USB_OTG_DTHRCTL_RXTHRLEN_1              ((uint32_t)0x00040000)            /*!<Bit 1 */
#define USB_OTG_DTHRCTL_RXTHRLEN_2              ((uint32_t)0x00080000)            /*!<Bit 2 */
#define USB_OTG_DTHRCTL_RXTHRLEN_3              ((uint32_t)0x00100000)            /*!<Bit 3 */
#define USB_OTG_DTHRCTL_RXTHRLEN_4              ((uint32_t)0x00200000)            /*!<Bit 4 */
#define USB_OTG_DTHRCTL_RXTHRLEN_5              ((uint32_t)0x00400000)            /*!<Bit 5 */
#define USB_OTG_DTHRCTL_RXTHRLEN_6              ((uint32_t)0x00800000)            /*!<Bit 6 */
#define USB_OTG_DTHRCTL_RXTHRLEN_7              ((uint32_t)0x01000000)            /*!<Bit 7 */
#define USB_OTG_DTHRCTL_RXTHRLEN_8              ((uint32_t)0x02000000)            /*!<Bit 8 */
#define USB_OTG_DTHRCTL_ARPEN                   ((uint32_t)0x08000000)            /*!< Arbiter parking enable */

/********************  Bit definition for USB_OTG_DIEPEMPMSK register  ********************/
#define USB_OTG_DIEPEMPMSK_INEPTXFEM               ((uint32_t)0x0000FFFF)         /*!< IN EP Tx FIFO empty interrupt mask bits */

/********************  Bit definition for USB_OTG_DEACHINT register  ********************/
#define USB_OTG_DEACHINT_IEP1INT                 ((uint32_t)0x00000002)           /*!< IN endpoint 1interrupt bit   */
#define USB_OTG_DEACHINT_OEP1INT                 ((uint32_t)0x00020000)           /*!< OUT endpoint 1 interrupt bit */

/********************  Bit definition for USB_OTG_GCCFG register  ********************/
#define USB_OTG_GCCFG_PWRDWN                 ((uint32_t)0x00010000)              /*!< Power down */
#define USB_OTG_GCCFG_VBDEN                  ((uint32_t)0x00200000)              /*!< USB VBUS Detection Enable */

/********************  Bit definition for USB_OTG_GPWRDN) register  ********************/
#define USB_OTG_GPWRDN_ADPMEN                 ((uint32_t)0x00000001)             /*!< ADP module enable */
#define USB_OTG_GPWRDN_ADPIF                  ((uint32_t)0x00800000)             /*!< ADP Interrupt flag */

/********************  Bit definition for USB_OTG_DEACHINTMSK register  ********************/
#define USB_OTG_DEACHINTMSK_IEP1INTM          ((uint32_t)0x00000002)            /*!< IN Endpoint 1 interrupt mask bit  */
#define USB_OTG_DEACHINTMSK_OEP1INTM          ((uint32_t)0x00020000)            /*!< OUT Endpoint 1 interrupt mask bit */
 
/********************  Bit definition for USB_OTG_CID register  ********************/
#define USB_OTG_CID_PRODUCT_ID               ((uint32_t)0xFFFFFFFF)            /*!< Product ID field */

/********************  Bit definition for USB_OTG_GLPMCFG register  ********************/
#define  USB_OTG_GLPMCFG_LPMEN               ((uint32_t)0x00000001)            /*!< LPM support enable                                     */
#define  USB_OTG_GLPMCFG_LPMACK              ((uint32_t)0x00000002)            /*!< LPM Token acknowledge enable                           */
#define  USB_OTG_GLPMCFG_BESL                ((uint32_t)0x0000003C)            /*!< BESL value received with last ACKed LPM Token          */
#define  USB_OTG_GLPMCFG_REMWAKE             ((uint32_t)0x00000040)            /*!< bRemoteWake value received with last ACKed LPM Token   */
#define  USB_OTG_GLPMCFG_L1SSEN              ((uint32_t)0x00000080)            /*!< L1 shallow sleep enable                                */
#define  USB_OTG_GLPMCFG_BESLTHRS            ((uint32_t)0x00000F00)            /*!< BESL threshold                                         */
#define  USB_OTG_GLPMCFG_L1DSEN              ((uint32_t)0x00001000)            /*!< L1 deep sleep enable                                   */
#define  USB_OTG_GLPMCFG_LPMRSP              ((uint32_t)0x00006000)            /*!< LPM response                                           */
#define  USB_OTG_GLPMCFG_SLPSTS              ((uint32_t)0x00008000)            /*!< Port sleep status                                      */
#define  USB_OTG_GLPMCFG_L1RSMOK             ((uint32_t)0x00010000)            /*!< Sleep State Resume OK                                  */
#define  USB_OTG_GLPMCFG_LPMCHIDX            ((uint32_t)0x001E0000)            /*!< LPM Channel Index                                      */
#define  USB_OTG_GLPMCFG_LPMRCNT             ((uint32_t)0x00E00000)            /*!< LPM retry count                                        */
#define  USB_OTG_GLPMCFG_SNDLPM              ((uint32_t)0x01000000)            /*!< Send LPM transaction                                   */
#define  USB_OTG_GLPMCFG_LPMRCNTSTS          ((uint32_t)0x0E000000)            /*!< LPM retry count status                                 */
#define  USB_OTG_GLPMCFG_ENBESL              ((uint32_t)0x10000000)            /*!< Enable best effort service latency                     */

/********************  Bit definition for USB_OTG_DIEPEACHMSK1 register  ********************/
#define USB_OTG_DIEPEACHMSK1_XFRCM           ((uint32_t)0x00000001)            /*!< Transfer completed interrupt mask                 */
#define USB_OTG_DIEPEACHMSK1_EPDM            ((uint32_t)0x00000002)            /*!< Endpoint disabled interrupt mask                  */
#define USB_OTG_DIEPEACHMSK1_TOM             ((uint32_t)0x00000008)            /*!< Timeout condition mask (nonisochronous endpoints) */
#define USB_OTG_DIEPEACHMSK1_ITTXFEMSK       ((uint32_t)0x00000010)            /*!< IN token received when TxFIFO empty mask          */
#define USB_OTG_DIEPEACHMSK1_INEPNMM         ((uint32_t)0x00000020)            /*!< IN token received with EP mismatch mask           */
#define USB_OTG_DIEPEACHMSK1_INEPNEM         ((uint32_t)0x00000040)            /*!< IN endpoint NAK effective mask                    */
#define USB_OTG_DIEPEACHMSK1_TXFURM          ((uint32_t)0x00000100)            /*!< FIFO underrun mask                                */
#define USB_OTG_DIEPEACHMSK1_BIM             ((uint32_t)0x00000200)            /*!< BNA interrupt mask                                */
#define USB_OTG_DIEPEACHMSK1_NAKM            ((uint32_t)0x00002000)            /*!< NAK interrupt mask                                */

/********************  Bit definition for USB_OTG_HPRT register  ********************/
#define USB_OTG_HPRT_PCSTS                   ((uint32_t)0x00000001)            /*!< Port connect status        */
#define USB_OTG_HPRT_PCDET                   ((uint32_t)0x00000002)            /*!< Port connect detected      */
#define USB_OTG_HPRT_PENA                    ((uint32_t)0x00000004)            /*!< Port enable                */
#define USB_OTG_HPRT_PENCHNG                 ((uint32_t)0x00000008)            /*!< Port enable/disable change */
#define USB_OTG_HPRT_POCA                    ((uint32_t)0x00000010)            /*!< Port overcurrent active    */
#define USB_OTG_HPRT_POCCHNG                 ((uint32_t)0x00000020)            /*!< Port overcurrent change    */
#define USB_OTG_HPRT_PRES                    ((uint32_t)0x00000040)            /*!< Port resume                */
#define USB_OTG_HPRT_PSUSP                   ((uint32_t)0x00000080)            /*!< Port suspend               */
#define USB_OTG_HPRT_PRST                    ((uint32_t)0x00000100)            /*!< Port reset                 */

#define USB_OTG_HPRT_PLSTS                   ((uint32_t)0x00000C00)            /*!< Port line status           */
#define USB_OTG_HPRT_PLSTS_0                 ((uint32_t)0x00000400)            /*!<Bit 0 */
#define USB_OTG_HPRT_PLSTS_1                 ((uint32_t)0x00000800)            /*!<Bit 1 */
#define USB_OTG_HPRT_PPWR                    ((uint32_t)0x00001000)            /*!< Port power                 */

#define USB_OTG_HPRT_PTCTL                   ((uint32_t)0x0001E000)            /*!< Port test control          */
#define USB_OTG_HPRT_PTCTL_0                 ((uint32_t)0x00002000)            /*!<Bit 0 */
#define USB_OTG_HPRT_PTCTL_1                 ((uint32_t)0x00004000)            /*!<Bit 1 */
#define USB_OTG_HPRT_PTCTL_2                 ((uint32_t)0x00008000)            /*!<Bit 2 */
#define USB_OTG_HPRT_PTCTL_3                 ((uint32_t)0x00010000)            /*!<Bit 3 */

#define USB_OTG_HPRT_PSPD                    ((uint32_t)0x00060000)            /*!< Port speed                 */
#define USB_OTG_HPRT_PSPD_0                  ((uint32_t)0x00020000)            /*!<Bit 0 */
#define USB_OTG_HPRT_PSPD_1                  ((uint32_t)0x00040000)            /*!<Bit 1 */

/********************  Bit definition for USB_OTG_DOEPEACHMSK1 register  ********************/
#define USB_OTG_DOEPEACHMSK1_XFRCM                   ((uint32_t)0x00000001)            /*!< Transfer completed interrupt mask         */
#define USB_OTG_DOEPEACHMSK1_EPDM                    ((uint32_t)0x00000002)            /*!< Endpoint disabled interrupt mask          */
#define USB_OTG_DOEPEACHMSK1_TOM                     ((uint32_t)0x00000008)            /*!< Timeout condition mask                    */
#define USB_OTG_DOEPEACHMSK1_ITTXFEMSK               ((uint32_t)0x00000010)            /*!< IN token received when TxFIFO empty mask  */
#define USB_OTG_DOEPEACHMSK1_INEPNMM                 ((uint32_t)0x00000020)            /*!< IN token received with EP mismatch mask   */
#define USB_OTG_DOEPEACHMSK1_INEPNEM                 ((uint32_t)0x00000040)            /*!< IN endpoint NAK effective mask            */
#define USB_OTG_DOEPEACHMSK1_TXFURM                  ((uint32_t)0x00000100)            /*!< OUT packet error mask                     */
#define USB_OTG_DOEPEACHMSK1_BIM                     ((uint32_t)0x00000200)            /*!< BNA interrupt mask                        */
#define USB_OTG_DOEPEACHMSK1_BERRM                   ((uint32_t)0x00001000)            /*!< Bubble error interrupt mask               */
#define USB_OTG_DOEPEACHMSK1_NAKM                    ((uint32_t)0x00002000)            /*!< NAK interrupt mask                        */
#define USB_OTG_DOEPEACHMSK1_NYETM                   ((uint32_t)0x00004000)            /*!< NYET interrupt mask                       */

/********************  Bit definition for USB_OTG_HPTXFSIZ register  ********************/
#define USB_OTG_HPTXFSIZ_PTXSA                   ((uint32_t)0x0000FFFF)            /*!< Host periodic TxFIFO start address            */
#define USB_OTG_HPTXFSIZ_PTXFD                   ((uint32_t)0xFFFF0000)            /*!< Host periodic TxFIFO depth                    */

/********************  Bit definition for USB_OTG_DIEPCTL register  ********************/
#define USB_OTG_DIEPCTL_MPSIZ                   ((uint32_t)0x000007FF)            /*!< Maximum packet size              */
#define USB_OTG_DIEPCTL_USBAEP                  ((uint32_t)0x00008000)            /*!< USB active endpoint              */
#define USB_OTG_DIEPCTL_EONUM_DPID              ((uint32_t)0x00010000)            /*!< Even/odd frame                   */
#define USB_OTG_DIEPCTL_NAKSTS                  ((uint32_t)0x00020000)            /*!< NAK status                       */

#define USB_OTG_DIEPCTL_EPTYP                   ((uint32_t)0x000C0000)            /*!< Endpoint type                    */
#define USB_OTG_DIEPCTL_EPTYP_0                 ((uint32_t)0x00040000)            /*!<Bit 0 */
#define USB_OTG_DIEPCTL_EPTYP_1                 ((uint32_t)0x00080000)            /*!<Bit 1 */
#define USB_OTG_DIEPCTL_STALL                   ((uint32_t)0x00200000)            /*!< STALL handshake                  */

#define USB_OTG_DIEPCTL_TXFNUM                  ((uint32_t)0x03C00000)            /*!< TxFIFO number                    */
#define USB_OTG_DIEPCTL_TXFNUM_0                ((uint32_t)0x00400000)            /*!<Bit 0 */
#define USB_OTG_DIEPCTL_TXFNUM_1                ((uint32_t)0x00800000)            /*!<Bit 1 */
#define USB_OTG_DIEPCTL_TXFNUM_2                ((uint32_t)0x01000000)            /*!<Bit 2 */
#define USB_OTG_DIEPCTL_TXFNUM_3                ((uint32_t)0x02000000)            /*!<Bit 3 */
#define USB_OTG_DIEPCTL_CNAK                    ((uint32_t)0x04000000)            /*!< Clear NAK                        */
#define USB_OTG_DIEPCTL_SNAK                    ((uint32_t)0x08000000)            /*!< Set NAK */
#define USB_OTG_DIEPCTL_SD0PID_SEVNFRM          ((uint32_t)0x10000000)            /*!< Set DATA0 PID                    */
#define USB_OTG_DIEPCTL_SODDFRM                 ((uint32_t)0x20000000)            /*!< Set odd frame                    */
#define USB_OTG_DIEPCTL_EPDIS                   ((uint32_t)0x40000000)            /*!< Endpoint disable                 */
#define USB_OTG_DIEPCTL_EPENA                   ((uint32_t)0x80000000)            /*!< Endpoint enable                  */

/********************  Bit definition for USB_OTG_HCCHAR register  ********************/
#define USB_OTG_HCCHAR_MPSIZ                   ((uint32_t)0x000007FF)            /*!< Maximum packet size */

#define USB_OTG_HCCHAR_EPNUM                   ((uint32_t)0x00007800)            /*!< Endpoint number */
#define USB_OTG_HCCHAR_EPNUM_0                 ((uint32_t)0x00000800)            /*!<Bit 0 */
#define USB_OTG_HCCHAR_EPNUM_1                 ((uint32_t)0x00001000)            /*!<Bit 1 */
#define USB_OTG_HCCHAR_EPNUM_2                 ((uint32_t)0x00002000)            /*!<Bit 2 */
#define USB_OTG_HCCHAR_EPNUM_3                 ((uint32_t)0x00004000)            /*!<Bit 3 */
#define USB_OTG_HCCHAR_EPDIR                   ((uint32_t)0x00008000)            /*!< Endpoint direction */
#define USB_OTG_HCCHAR_LSDEV                   ((uint32_t)0x00020000)            /*!< Low-speed device */

#define USB_OTG_HCCHAR_EPTYP                   ((uint32_t)0x000C0000)            /*!< Endpoint type */
#define USB_OTG_HCCHAR_EPTYP_0                 ((uint32_t)0x00040000)            /*!<Bit 0 */
#define USB_OTG_HCCHAR_EPTYP_1                 ((uint32_t)0x00080000)            /*!<Bit 1 */

#define USB_OTG_HCCHAR_MC                      ((uint32_t)0x00300000)            /*!< Multi Count (MC) / Error Count (EC) */
#define USB_OTG_HCCHAR_MC_0                    ((uint32_t)0x00100000)            /*!<Bit 0 */
#define USB_OTG_HCCHAR_MC_1                    ((uint32_t)0x00200000)            /*!<Bit 1 */

#define USB_OTG_HCCHAR_DAD                     ((uint32_t)0x1FC00000)            /*!< Device address */
#define USB_OTG_HCCHAR_DAD_0                   ((uint32_t)0x00400000)            /*!<Bit 0 */
#define USB_OTG_HCCHAR_DAD_1                   ((uint32_t)0x00800000)            /*!<Bit 1 */
#define USB_OTG_HCCHAR_DAD_2                   ((uint32_t)0x01000000)            /*!<Bit 2 */
#define USB_OTG_HCCHAR_DAD_3                   ((uint32_t)0x02000000)            /*!<Bit 3 */
#define USB_OTG_HCCHAR_DAD_4                   ((uint32_t)0x04000000)            /*!<Bit 4 */
#define USB_OTG_HCCHAR_DAD_5                   ((uint32_t)0x08000000)            /*!<Bit 5 */
#define USB_OTG_HCCHAR_DAD_6                   ((uint32_t)0x10000000)            /*!<Bit 6 */
#define USB_OTG_HCCHAR_ODDFRM                  ((uint32_t)0x20000000)            /*!< Odd frame */
#define USB_OTG_HCCHAR_CHDIS                   ((uint32_t)0x40000000)            /*!< Channel disable */
#define USB_OTG_HCCHAR_CHENA                   ((uint32_t)0x80000000)            /*!< Channel enable */

/********************  Bit definition for USB_OTG_HCSPLT register  ********************/

#define USB_OTG_HCSPLT_PRTADDR                 ((uint32_t)0x0000007F)            /*!< Port address */
#define USB_OTG_HCSPLT_PRTADDR_0               ((uint32_t)0x00000001)            /*!<Bit 0 */
#define USB_OTG_HCSPLT_PRTADDR_1               ((uint32_t)0x00000002)            /*!<Bit 1 */
#define USB_OTG_HCSPLT_PRTADDR_2               ((uint32_t)0x00000004)            /*!<Bit 2 */
#define USB_OTG_HCSPLT_PRTADDR_3               ((uint32_t)0x00000008)            /*!<Bit 3 */
#define USB_OTG_HCSPLT_PRTADDR_4               ((uint32_t)0x00000010)            /*!<Bit 4 */
#define USB_OTG_HCSPLT_PRTADDR_5               ((uint32_t)0x00000020)            /*!<Bit 5 */
#define USB_OTG_HCSPLT_PRTADDR_6               ((uint32_t)0x00000040)            /*!<Bit 6 */

#define USB_OTG_HCSPLT_HUBADDR                 ((uint32_t)0x00003F80)            /*!< Hub address */
#define USB_OTG_HCSPLT_HUBADDR_0               ((uint32_t)0x00000080)            /*!<Bit 0 */
#define USB_OTG_HCSPLT_HUBADDR_1               ((uint32_t)0x00000100)            /*!<Bit 1 */
#define USB_OTG_HCSPLT_HUBADDR_2               ((uint32_t)0x00000200)            /*!<Bit 2 */
#define USB_OTG_HCSPLT_HUBADDR_3               ((uint32_t)0x00000400)            /*!<Bit 3 */
#define USB_OTG_HCSPLT_HUBADDR_4               ((uint32_t)0x00000800)            /*!<Bit 4 */
#define USB_OTG_HCSPLT_HUBADDR_5               ((uint32_t)0x00001000)            /*!<Bit 5 */
#define USB_OTG_HCSPLT_HUBADDR_6               ((uint32_t)0x00002000)            /*!<Bit 6 */

#define USB_OTG_HCSPLT_XACTPOS                 ((uint32_t)0x0000C000)            /*!< XACTPOS */
#define USB_OTG_HCSPLT_XACTPOS_0               ((uint32_t)0x00004000)            /*!<Bit 0 */
#define USB_OTG_HCSPLT_XACTPOS_1               ((uint32_t)0x00008000)            /*!<Bit 1 */
#define USB_OTG_HCSPLT_COMPLSPLT               ((uint32_t)0x00010000)            /*!< Do complete split */
#define USB_OTG_HCSPLT_SPLITEN                 ((uint32_t)0x80000000)            /*!< Split enable */

/********************  Bit definition for USB_OTG_HCINT register  ********************/
#define USB_OTG_HCINT_XFRC                    ((uint32_t)0x00000001)            /*!< Transfer completed */
#define USB_OTG_HCINT_CHH                     ((uint32_t)0x00000002)            /*!< Channel halted */
#define USB_OTG_HCINT_AHBERR                  ((uint32_t)0x00000004)            /*!< AHB error */
#define USB_OTG_HCINT_STALL                   ((uint32_t)0x00000008)            /*!< STALL response received interrupt */
#define USB_OTG_HCINT_NAK                     ((uint32_t)0x00000010)            /*!< NAK response received interrupt */
#define USB_OTG_HCINT_ACK                     ((uint32_t)0x00000020)            /*!< ACK response received/transmitted interrupt */
#define USB_OTG_HCINT_NYET                    ((uint32_t)0x00000040)            /*!< Response received interrupt */
#define USB_OTG_HCINT_TXERR                   ((uint32_t)0x00000080)            /*!< Transaction error */
#define USB_OTG_HCINT_BBERR                   ((uint32_t)0x00000100)            /*!< Babble error */
#define USB_OTG_HCINT_FRMOR                   ((uint32_t)0x00000200)            /*!< Frame overrun */
#define USB_OTG_HCINT_DTERR                   ((uint32_t)0x00000400)            /*!< Data toggle error */

/********************  Bit definition for USB_OTG_DIEPINT register  ********************/
#define USB_OTG_DIEPINT_XFRC                    ((uint32_t)0x00000001)            /*!< Transfer completed interrupt */
#define USB_OTG_DIEPINT_EPDISD                  ((uint32_t)0x00000002)            /*!< Endpoint disabled interrupt */
#define USB_OTG_DIEPINT_TOC                     ((uint32_t)0x00000008)            /*!< Timeout condition */
#define USB_OTG_DIEPINT_ITTXFE                  ((uint32_t)0x00000010)            /*!< IN token received when TxFIFO is empty */
#define USB_OTG_DIEPINT_INEPNE                  ((uint32_t)0x00000040)            /*!< IN endpoint NAK effective */
#define USB_OTG_DIEPINT_TXFE                    ((uint32_t)0x00000080)            /*!< Transmit FIFO empty */
#define USB_OTG_DIEPINT_TXFIFOUDRN              ((uint32_t)0x00000100)            /*!< Transmit Fifo Underrun */
#define USB_OTG_DIEPINT_BNA                     ((uint32_t)0x00000200)            /*!< Buffer not available interrupt */
#define USB_OTG_DIEPINT_PKTDRPSTS               ((uint32_t)0x00000800)            /*!< Packet dropped status */
#define USB_OTG_DIEPINT_BERR                    ((uint32_t)0x00001000)            /*!< Babble error interrupt */
#define USB_OTG_DIEPINT_NAK                     ((uint32_t)0x00002000)            /*!< NAK interrupt */

/********************  Bit definition for USB_OTG_HCINTMSK register  ********************/
#define USB_OTG_HCINTMSK_XFRCM                   ((uint32_t)0x00000001)            /*!< Transfer completed mask */
#define USB_OTG_HCINTMSK_CHHM                    ((uint32_t)0x00000002)            /*!< Channel halted mask */
#define USB_OTG_HCINTMSK_AHBERR                  ((uint32_t)0x00000004)            /*!< AHB error */
#define USB_OTG_HCINTMSK_STALLM                  ((uint32_t)0x00000008)            /*!< STALL response received interrupt mask */
#define USB_OTG_HCINTMSK_NAKM                    ((uint32_t)0x00000010)            /*!< NAK response received interrupt mask */
#define USB_OTG_HCINTMSK_ACKM                    ((uint32_t)0x00000020)            /*!< ACK response received/transmitted interrupt mask */
#define USB_OTG_HCINTMSK_NYET                    ((uint32_t)0x00000040)            /*!< response received interrupt mask */
#define USB_OTG_HCINTMSK_TXERRM                  ((uint32_t)0x00000080)            /*!< Transaction error mask */
#define USB_OTG_HCINTMSK_BBERRM                  ((uint32_t)0x00000100)            /*!< Babble error mask */
#define USB_OTG_HCINTMSK_FRMORM                  ((uint32_t)0x00000200)            /*!< Frame overrun mask */
#define USB_OTG_HCINTMSK_DTERRM                  ((uint32_t)0x00000400)            /*!< Data toggle error mask */

/********************  Bit definition for USB_OTG_DIEPTSIZ register  ********************/

#define USB_OTG_DIEPTSIZ_XFRSIZ                  ((uint32_t)0x0007FFFF)            /*!< Transfer size */
#define USB_OTG_DIEPTSIZ_PKTCNT                  ((uint32_t)0x1FF80000)            /*!< Packet count */
#define USB_OTG_DIEPTSIZ_MULCNT                  ((uint32_t)0x60000000)            /*!< Packet count */
/********************  Bit definition for USB_OTG_HCTSIZ register  ********************/
#define USB_OTG_HCTSIZ_XFRSIZ                    ((uint32_t)0x0007FFFF)            /*!< Transfer size */
#define USB_OTG_HCTSIZ_PKTCNT                    ((uint32_t)0x1FF80000)            /*!< Packet count */
#define USB_OTG_HCTSIZ_DOPING                    ((uint32_t)0x80000000)            /*!< Do PING */
#define USB_OTG_HCTSIZ_DPID                      ((uint32_t)0x60000000)            /*!< Data PID */
#define USB_OTG_HCTSIZ_DPID_0                    ((uint32_t)0x20000000)            /*!<Bit 0 */
#define USB_OTG_HCTSIZ_DPID_1                    ((uint32_t)0x40000000)            /*!<Bit 1 */

/********************  Bit definition for USB_OTG_DIEPDMA register  ********************/
#define USB_OTG_DIEPDMA_DMAADDR                  ((uint32_t)0xFFFFFFFF)            /*!< DMA address */

/********************  Bit definition for USB_OTG_HCDMA register  ********************/
#define USB_OTG_HCDMA_DMAADDR                    ((uint32_t)0xFFFFFFFF)            /*!< DMA address */

/********************  Bit definition for USB_OTG_DTXFSTS register  ********************/
#define USB_OTG_DTXFSTS_INEPTFSAV                ((uint32_t)0x0000FFFF)            /*!< IN endpoint TxFIFO space available */

/********************  Bit definition for USB_OTG_DIEPTXF register  ********************/
#define USB_OTG_DIEPTXF_INEPTXSA                 ((uint32_t)0x0000FFFF)            /*!< IN endpoint FIFOx transmit RAM start address */
#define USB_OTG_DIEPTXF_INEPTXFD                 ((uint32_t)0xFFFF0000)            /*!< IN endpoint TxFIFO depth */

/********************  Bit definition for USB_OTG_DOEPCTL register  ********************/
#define USB_OTG_DOEPCTL_MPSIZ                     ((uint32_t)0x000007FF)            /*!< Maximum packet size */          /*!<Bit 1 */
#define USB_OTG_DOEPCTL_USBAEP                    ((uint32_t)0x00008000)            /*!< USB active endpoint */
#define USB_OTG_DOEPCTL_NAKSTS                    ((uint32_t)0x00020000)            /*!< NAK status */
#define USB_OTG_DOEPCTL_SD0PID_SEVNFRM            ((uint32_t)0x10000000)            /*!< Set DATA0 PID */
#define USB_OTG_DOEPCTL_SODDFRM                   ((uint32_t)0x20000000)            /*!< Set odd frame */
#define USB_OTG_DOEPCTL_EPTYP                     ((uint32_t)0x000C0000)            /*!< Endpoint type */
#define USB_OTG_DOEPCTL_EPTYP_0                   ((uint32_t)0x00040000)            /*!<Bit 0 */
#define USB_OTG_DOEPCTL_EPTYP_1                   ((uint32_t)0x00080000)            /*!<Bit 1 */
#define USB_OTG_DOEPCTL_SNPM                      ((uint32_t)0x00100000)            /*!< Snoop mode */
#define USB_OTG_DOEPCTL_STALL                     ((uint32_t)0x00200000)            /*!< STALL handshake */
#define USB_OTG_DOEPCTL_CNAK                      ((uint32_t)0x04000000)            /*!< Clear NAK */
#define USB_OTG_DOEPCTL_SNAK                      ((uint32_t)0x08000000)            /*!< Set NAK */
#define USB_OTG_DOEPCTL_EPDIS                     ((uint32_t)0x40000000)            /*!< Endpoint disable */
#define USB_OTG_DOEPCTL_EPENA                     ((uint32_t)0x80000000)            /*!< Endpoint enable */

/********************  Bit definition for USB_OTG_DOEPINT register  ********************/
#define USB_OTG_DOEPINT_XFRC                    ((uint32_t)0x00000001)            /*!< Transfer completed interrupt */
#define USB_OTG_DOEPINT_EPDISD                  ((uint32_t)0x00000002)            /*!< Endpoint disabled interrupt */
#define USB_OTG_DOEPINT_STUP                    ((uint32_t)0x00000008)            /*!< SETUP phase done */
#define USB_OTG_DOEPINT_OTEPDIS                 ((uint32_t)0x00000010)            /*!< OUT token received when endpoint disabled */
#define USB_OTG_DOEPINT_B2BSTUP                 ((uint32_t)0x00000040)            /*!< Back-to-back SETUP packets received */
#define USB_OTG_DOEPINT_NYET                    ((uint32_t)0x00004000)            /*!< NYET interrupt */

/********************  Bit definition for USB_OTG_DOEPTSIZ register  ********************/
#define USB_OTG_DOEPTSIZ_XFRSIZ                  ((uint32_t)0x0007FFFF)            /*!< Transfer size */
#define USB_OTG_DOEPTSIZ_PKTCNT                  ((uint32_t)0x1FF80000)            /*!< Packet count */

#define USB_OTG_DOEPTSIZ_STUPCNT                 ((uint32_t)0x60000000)            /*!< SETUP packet count */
#define USB_OTG_DOEPTSIZ_STUPCNT_0               ((uint32_t)0x20000000)            /*!<Bit 0 */
#define USB_OTG_DOEPTSIZ_STUPCNT_1               ((uint32_t)0x40000000)            /*!<Bit 1 */

/********************  Bit definition for PCGCCTL register  ********************/
#define USB_OTG_PCGCCTL_STOPCLK                 ((uint32_t)0x00000001)            /*!< SETUP packet count */
#define USB_OTG_PCGCCTL_GATECLK                 ((uint32_t)0x00000002)            /*!<Bit 0 */
#define USB_OTG_PCGCCTL_PHYSUSP                 ((uint32_t)0x00000010)            /*!<Bit 1 */

#endif
