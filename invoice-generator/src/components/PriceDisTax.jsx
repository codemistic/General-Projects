import React from 'react';

export const PriceDisTax = (props) => {
    return (
        <>
            <div>
                <label className='fw-bold form-label'>{props.label}</label>
            </div>
            <div className='mb-2 flex-nowrap input-group'>
                <input
                    name='discountRate'
                    placeholder='0.0'
                    min='0.00'
                    step='0.01'
                    max='100.00'
                    type='number'
                    className='bg-white border form-control'
                    value={props.val}
                    onChange={(e) => props.changeRate(e.target.value)}
                />
                <span className='bg-light fw-bold text-secondary small input-group-text'>{props.icon}</span>
            </div>
        </>
    );
};
