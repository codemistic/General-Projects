import React from 'react';

export const TotalComponent = (props) => {
    return (
        <div className='d-flex align-items-start justify-content-between mb-2'>
            <span className='fw-bold'>{props.name}</span>
            <span>
                {props.extra !== undefined && `(${props.extra}%) `}
                {props.currency}
                {props.val}
            </span>
        </div>
    );
};
