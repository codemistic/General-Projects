import React from 'react';
import Row from 'react-bootstrap/Row';

import Table from 'react-bootstrap/Table';
import Modal from 'react-bootstrap/Modal';
import html2canvas from 'html2canvas';
import jsPDF from 'jspdf';
export const InvoiceModal = (props) => {
    function GenerateInvoice() {
        html2canvas(document.querySelector('#invoiceCapture')).then((canvas) => {
            const imgData = canvas.toDataURL('image/png', 1.0);
            let fmt = props.isMobile ? [600, 1400] : [700, 900];

            const pdf = new jsPDF({
                orientation: 'portrait',
                unit: 'pt',
                format: fmt
            });
            pdf.internal.scaleFactor = 1;
            const imgProps = pdf.getImageProperties(imgData);
            const pdfWidth = pdf.internal.pageSize.getWidth();
            const pdfHeight = (imgProps.height * pdfWidth) / imgProps.width;
            pdf.addImage(imgData, 'PNG', 0, 0, pdfWidth, pdfHeight);
            if (props.isMobile) {
                pdf.save(`invoice${Math.floor(Math.random() * 100)}.pdf`);
            } else {
                window.open(URL.createObjectURL(pdf.output('blob')));
            }
        });
    }
    return (
        <div>
            <Modal show={props.show} onHide={props.onHide} size='lg' centered>
                <div id='invoiceCapture'>
                    <div className='d-flex justify-content-between align-items-start w-100 bg-light'>
                        <div className='px-4 py-4'>
                            <h4 className='fw-bold'>{props.billTo.toWhom}</h4>
                            <h6 className=' fw-bold text-secondary'>Invoice #: 1</h6>
                        </div>
                        <div className='px-4 py-4 text-end'>
                            <h4 className='fw-bold'>Amount Due:</h4>
                            <h6 className=' fw-bold text-secondary'>${props.bill.total}</h6>
                        </div>
                    </div>
                    <div className='p-4 mb-0 pb-0'>
                        <Row className='mb-4'>
                            <div className='col-md-4 mb-2 mb-xl-0'>
                                <div className='fw-bold'>Billed To:</div>
                                <div>{props.billTo.toWhom}</div>
                                <div>{props.billTo.billingAddress}</div>
                                <div>{props.billTo.emailAddress}</div>
                            </div>
                            <div className='col-md-4 mb-2 mb-xl-0'>
                                <div className='fw-bold'>Billed From:</div>
                                <div>{props.billFrom.fromWhom}</div>
                                <div>{props.billFrom.billingAddress}</div>
                                <div>{props.billFrom.emailAddress}</div>
                            </div>
                            <div className='col-md-4 mb-xl-0'>
                                <div className='fw-bold'>Date Of Issue:</div>
                                <div className='div'>{props.date}</div>
                            </div>
                        </Row>
                        <Table>
                            <thead>
                                <tr>
                                    <th>QTY</th>
                                    <th>DESCRIPTION</th>
                                    <th className='text-end'>PRICE</th>
                                    <th className='text-end'>AMOUNT</th>
                                </tr>
                            </thead>
                            <tbody>
                                {props.items.map((item) => {
                                    return (
                                        <tr key={item.id} className='text-end'>
                                            <td>{item.id + 1}</td>
                                            <td>{item.itemName}</td>
                                            <td className='text-end'>
                                                {props.currency} {item.price}
                                            </td>
                                            <td className='text-end'>
                                                {props.currency} {item.price}
                                            </td>
                                        </tr>
                                    );
                                })}
                            </tbody>
                        </Table>
                        <Table>
                            <tbody>
                                <tr>
                                    <td className='p-0'>&nbsp;</td>
                                    <td className='p-0'>&nbsp;</td>
                                    <td className='p-0'>&nbsp;</td>
                                </tr>
                                <tr className='text-end'>
                                    <td></td>
                                    <td className='fw-bold text-end' style={{ width: '100px' }}>
                                        SUBTOTAL
                                    </td>
                                    <td className='text-end' style={{ width: '100px' }}>
                                        {props.currency} {props.bill.subTotal}
                                    </td>
                                </tr>
                                <tr className='text-end'>
                                    <td></td>
                                    <td className='fw-bold text-end' style={{ width: '100px' }}>
                                        TOTAL
                                    </td>
                                    <td className='text-end' style={{ width: '100px' }}>
                                        {props.currency} {props.bill.total}
                                    </td>
                                </tr>
                            </tbody>
                        </Table>
                    </div>
                    <div className='w-100 mx-4 bg-light py-2 px-2 rounded fw-bold'>{props.notes}</div>
                </div>
                <div className='row p-3'>
                    <div className='col'>
                        <button className='w-100 btn btn-primary' onClick={GenerateInvoice}>
                            <i class='fa-solid fa-paper-plane'></i> Send Invoice
                        </button>
                    </div>
                    <div className='col'>
                        <button className='w-100 btn btn-outline-primary' onClick={GenerateInvoice}>
                            <i class='fa-solid fa-cloud-arrow-down'></i> Download Copy
                        </button>
                    </div>
                </div>
            </Modal>
        </div>
    );
};
