#include "firmament.h"
#include <rtthread.h>
#include "hal/usbd_cdc.h"

static rt_err_t hal_usbd_cdc_init(rt_device_t device)
{
	usbd_cdc_dev_t dev = (usbd_cdc_dev_t)device;

	dev->ops->usbd_cdc_dev_init(device);
	
	return RT_EOK;
}

static rt_size_t hal_usbd_cdc_read(rt_device_t device, rt_off_t pos, void* buffer, rt_size_t size)
{
	usbd_cdc_dev_t dev = (usbd_cdc_dev_t)device;

	rt_size_t res;

	if(*(dev->connect_status)){
		res = dev->ops->usbd_cdc_dev_read(device,pos,(void*)buffer,size);
	}

	return res;
}

static rt_size_t hal_usbd_cdc_write(rt_device_t device, rt_off_t pos, const void* buffer, rt_size_t size)
{
	usbd_cdc_dev_t dev = (usbd_cdc_dev_t)device;

	if(*(dev->connect_status)){

		while(*(dev->tx_stutus) != 0)	rt_thread_delay(1);/* waiting for usbd_cdc_dev tx ready. in release version , must add re_thread_delay*/
		dev->ops->usbd_cdc_dev_write(device,pos,(void*)buffer,size);


		if(device->tx_complete != RT_NULL){
			device->tx_complete(device,(void*)buffer);
		}

		return size;
		
	}else{
		return 0;
	}
}

rt_err_t hal_usbd_cdc_register(usbd_cdc_dev_t device, const char* name, rt_uint16_t flag, void* data)
{
	rt_err_t res;

	rt_device_t dev = &device->parent;

	dev->type        = RT_Device_Class_USBDevice;
	dev->ref_count   = 0;

	dev->rx_indicate = RT_NULL;
	dev->tx_complete = RT_NULL;

	dev->init        = hal_usbd_cdc_init;
	dev->open        = RT_NULL;
	dev->close       = RT_NULL;
	dev->read        = hal_usbd_cdc_read;
	dev->write       = hal_usbd_cdc_write;
	dev->control     = RT_NULL;

	dev->user_data   = RT_NULL;

	/* register to device manager */
    res = rt_device_register(dev,name,flag);
    
	return res;
}