import React, { useEffect, useState } from 'react';
import Row from 'react-bootstrap/Row';
import Col from 'react-bootstrap/Col';
import Button from 'react-bootstrap/Button';
import Card from 'react-bootstrap/Card';
import { InvoiceModal } from './InvoiceModal';
import { PriceDisTax } from './PriceDisTax';
import { CurrencyChange } from './CurrencyChange';
import { TotalComponent } from './TotalComponent';
import { ItemInputComponent } from './ItemInputComponent';
import { ItemBillDetails } from './ItemBillDetails';
import { Notes } from './Notes';

export const InvoiceForm = () => {
    const [items, setItems] = useState([{ id: 0, itemName: '', itemDescription: '', quantity: 1, price: 1 }]);
    const [date, setDate] = useState(new Date().toISOString().slice(0, 10));
    const [invoiceNum, setInvoiceNum] = useState(1);
    const [isMobile, setIsMobile] = useState(false);
    const [billTo, setBillTo] = useState({
        toWhom: '',
        emailAddress: '',
        billingAddress: ''
    });
    const [billFrom, setBillFrom] = useState({
        fromWhom: '',
        emailAddress: '',
        billingAddress: ''
    });
    const [currency, setCurrency] = useState('₹');
    const [taxRate, setTaxRate] = useState(18);
    const [discount, setDiscount] = useState(0);
    const [notes, setNotes] = useState('');
    const [show, setShow] = useState(false);
    const [bill, setBill] = useState({
        subTotal: 1,
        discount: 0.0,
        tax: 0.18,
        total: 1
    });
    useEffect(() => {
        const subTotal = items.reduce((acc, item) => parseFloat(item.price) * parseInt(item.quantity) + acc, 0);
        if (isNaN(subTotal)) {
            setBill({ subTotal: 0, discount: 0, tax: 0, total: 0 });
        } else {
            const discountAmount = ((subTotal * discount) / 100).toFixed(2);
            const newTax = (((subTotal - discountAmount) * taxRate) / 100).toFixed(2);
            const total = (subTotal - discountAmount).toFixed(2);

            setBill({ subTotal: subTotal, discount: discountAmount, tax: newTax, total: total });
        }
    }, [items, taxRate, discount]);

    const handleResize = () => {
        if (window.innerWidth < 720) {
            setIsMobile(true);
        } else {
            setIsMobile(false);
        }
    };

    useEffect(() => {
        window.addEventListener('resize', handleResize);

        return () => {
            window.removeEventListener('resize', handleResize);
        };
    });

    const itemChangeHandler = (e, index) => {
        const newItems = items.map((item) => {
            if (item.id === index) {
                return {
                    ...item,
                    [e.target.name]: e.target.value
                };
            } else {
                return item;
            }
        });

        setItems(newItems);
    };
    function deleteItems(e, id) {
        if (items.length === 1) {
            setItems([
                {
                    id: 0,
                    itemName: '',
                    itemDescription: '',
                    quantity: 1,
                    price: 1
                }
            ]);
        } else {
            const newItems = items.filter((elem, index) => {
                console.log(index, id);
                return index !== id;
            });
            setItems(newItems);
        }
    }
    return (
        <>
            <form
                onSubmit={(e) => {
                    setShow(true);
                    e.preventDefault();
                }}
            >
                <Row>
                    <Col lg={9} md={8}>
                        <Card className='p-3 my-5 mx-2 p-xl-4 my-xl-2'>
                            <div className='d-flex align-items-start justify-content-between mb-3'>
                                <div className='d-flex flex-column '>
                                    <div className='d-flex'>
                                        <div className='mb-2'>
                                            <span className='fw-bold'>Current Date: </span>
                                            <span>{new Date().toISOString().slice(0, 10)}</span>
                                        </div>
                                    </div>
                                    <div className='d-flex'>
                                        <div className='d-flex flex-row align-items-center'>
                                            <span className='fw-bold  d-block' style={{ minWidth: '70px' }}>
                                                Due Date:
                                            </span>
                                            <input
                                                type='date'
                                                className='form-control '
                                                name='dateofIssue'
                                                style={{ maxWidth: '200px', minWidth: '80px' }}
                                                required
                                                min={date}
                                                value={date}
                                                onChange={(e) => setDate(e.target.value)}
                                            />
                                        </div>
                                    </div>
                                </div>
                                <div className='d-flex flex-row align-items-center'>
                                    <span className='me-2 fw-bold'>Invoice Number: </span>
                                    <input
                                        type='number'
                                        min='1'
                                        name='invoiceNumber'
                                        className='form-control'
                                        value={invoiceNum}
                                        onChange={(e) => setInvoiceNum(e.target.value)}
                                        style={{ maxWidth: '70px' }}
                                        required
                                    />
                                </div>
                            </div>
                            <hr className='my-4' />
                            <div className='row mb-4'>
                                <div className='col'>
                                    <label className='fw-bold' htmlFor='toWhom'>
                                        Bill to:
                                    </label>
                                    <ItemBillDetails
                                        placeholder='Who is this invoice to?'
                                        name='toWhom'
                                        type='text'
                                        val={billTo.toWhom}
                                        setInput={setBillTo}
                                    />
                                    <ItemBillDetails
                                        placeholder='Email Address'
                                        name='emailAddress'
                                        val={billTo.emailAddress}
                                        type='email'
                                        setInput={setBillTo}
                                    />
                                    <ItemBillDetails
                                        placeholder='Billing Address'
                                        name='billingAddress'
                                        val={billTo.billingAddress}
                                        type='text'
                                        setInput={setBillTo}
                                    />
                                </div>
                                <div className='col'>
                                    <label className='fw-bold' htmlFor='fromWhom'>
                                        Bill From:
                                    </label>
                                    <ItemBillDetails
                                        placeholder='Who is this invoice from?'
                                        name='fromWhom'
                                        type='text'
                                        val={billFrom.fromWhom}
                                        setInput={setBillFrom}
                                    />
                                    <ItemBillDetails
                                        placeholder='Email Address'
                                        name='emailAddress'
                                        val={billFrom.emailAddress}
                                        type='email'
                                        setInput={setBillFrom}
                                    />
                                    <ItemBillDetails
                                        placeholder='Billing Address'
                                        name='billingAddress'
                                        val={billFrom.billingAddress}
                                        type='text'
                                        setInput={setBillFrom}
                                    />
                                </div>
                            </div>
                            <div>
                                <table className='table'>
                                    <thead>
                                        <tr>
                                            <th className='text-start'>ITEM</th>
                                            <th className='text-start'>QTY</th>
                                            <th className='text-start'>PRICE/RATE</th>
                                            <th className='text-end'>ACTION</th>
                                        </tr>
                                    </thead>
                                    <tbody>
                                        {items.map((item, index) => {
                                            return (
                                                <tr key={index}>
                                                    <td style={{ width: '70%' }} className='pe-0 input-lg'>
                                                        <ItemInputComponent
                                                            itemChangeHandler={itemChangeHandler}
                                                            index={index}
                                                            name='itemName'
                                                            placeholder='Item Name'
                                                            val={item.itemName}
                                                        />
                                                        <ItemInputComponent
                                                            itemChangeHandler={itemChangeHandler}
                                                            index={index}
                                                            name='itemDescription'
                                                            placeholder='Item Description'
                                                            val={item.itemDescription}
                                                        />
                                                    </td>
                                                    <td style={{ width: '100px' }} className='pe-0'>
                                                        <div className='my-1 flex-nowrap input-group'>
                                                            <input
                                                                type='number'
                                                                min='1'
                                                                name='quantity'
                                                                className='form-control'
                                                                style={{
                                                                    maxWidth: '70px'
                                                                }}
                                                                value={item.quantity}
                                                                onChange={(e) => itemChangeHandler(e, index)}
                                                                required
                                                            />
                                                        </div>
                                                    </td>
                                                    <td className='pe-0' style={{ width: '150px' }}>
                                                        <div className='my-1 flex-nowrap input-group'>
                                                            <span className='bg-light fw-bold border-0 text-secondary px-2 input-group-text'>
                                                                <span
                                                                    className='border border-2 border-secondary rounded-circle d-flex align-items-center justify-content-center small'
                                                                    style={{
                                                                        width: '20px',
                                                                        height: '20px'
                                                                    }}
                                                                >
                                                                    {currency}
                                                                </span>
                                                            </span>
                                                            <input
                                                                required
                                                                style={{
                                                                    width: '40px'
                                                                }}
                                                                type='number'
                                                                min='1'
                                                                step='0.1'
                                                                className='form-control'
                                                                value={item.price}
                                                                name='price'
                                                                onChange={(e) => itemChangeHandler(e, index)}
                                                            />
                                                        </div>
                                                    </td>
                                                    <td className='text-center pe-0' style={{ width: '60px' }}>
                                                        <svg
                                                            key={index}
                                                            onClick={(e) => {
                                                                deleteItems(e, index);
                                                            }}
                                                            stroke='currentColor'
                                                            fill='currentColor'
                                                            strokeWidth='0'
                                                            viewBox='0 0 24 24'
                                                            className='text-white mt-1 btn btn-danger'
                                                            height='1em'
                                                            width='1em'
                                                            xmlns='http://www.w3.org/2000/svg'
                                                            style={{
                                                                height: '33px',
                                                                width: '33px',
                                                                padding: '7.5px'
                                                            }}
                                                        >
                                                            <path
                                                                fill='none'
                                                                d='M17.004 20L17.003 8h-1-8-1v12H17.004zM13.003 10h2v8h-2V10zM9.003 10h2v8h-2V10zM9.003 4H15.003V6H9.003z'
                                                            ></path>
                                                            <path d='M5.003,20c0,1.103,0.897,2,2,2h10c1.103,0,2-0.897,2-2V8h2V6h-3h-1V4c0-1.103-0.897-2-2-2h-6c-1.103,0-2,0.897-2,2v2h-1h-3 v2h2V20z M9.003,4h6v2h-6V4z M8.003,8h8h1l0.001,12H7.003V8H8.003z'></path>
                                                            <path d='M9.003 10H11.003V18H9.003zM13.003 10H15.003V18H13.003z'></path>
                                                        </svg>
                                                    </td>
                                                </tr>
                                            );
                                        })}
                                    </tbody>
                                </table>
                                <Button
                                    className='mt-2 mb-3'
                                    style={{ fontSize: '1em' }}
                                    onClick={() =>
                                        setItems((prev) => {
                                            return [
                                                ...prev,
                                                {
                                                    id: items[items.length - 1].id + 1,
                                                    itemName: '',
                                                    itemDescription: '',
                                                    quantity: 1,
                                                    price: 1
                                                }
                                            ];
                                        })
                                    }
                                >
                                    Add Item
                                </Button>
                            </div>

                            <div className='row mt-2 justify-content-end'>
                                <div className='col-lg-6'>
                                    <TotalComponent name='Sub Total:' currency={currency} val={bill.subTotal} />
                                    <TotalComponent
                                        name='Discount:'
                                        currency={currency}
                                        val={bill.discount}
                                        extra={discount}
                                    />
                                    <TotalComponent name='Tax:' currency={currency} val={bill.tax} extra={taxRate} />
                                    <hr className='my-3' />
                                    <TotalComponent name='Total:' currency={currency} val={bill.total} />
                                </div>
                            </div>
                            <hr className='mt-4' />
                            <Notes notes={notes} setNotes={setNotes} />
                        </Card>
                    </Col>
                    <Col lg={3} md={4}>
                        <div className='sticky-top pt-xl-4 pt-md-3'>
                            <Button className='w-100' type='submit'>
                                Review Invoice
                            </Button>
                            <div className='mb-3 mt-4'>
                                <hr />
                            </div>
                            <CurrencyChange currency={currency} setCurrency={setCurrency} />
                            <PriceDisTax val={discount} changeRate={setDiscount} icon='%' label='Discount' />
                            <PriceDisTax val={taxRate} changeRate={setTaxRate} icon='%' label='Tax Rate:' />
                        </div>
                    </Col>
                </Row>
            </form>
            <InvoiceModal
                show={show}
                date={new Date().toISOString().slice(0, 10)}
                onHide={() => setShow(false)}
                invoiceNum={invoiceNum}
                billFrom={billFrom}
                billTo={billTo}
                items={items}
                bill={bill}
                notes={notes}
                currency={currency}
                isMobile={isMobile}
            />
        </>
    );
};
