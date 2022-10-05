import React from 'react';
import '../node_modules/bootstrap/dist/css/bootstrap.min.css';
import './App.css';

import Container from 'react-bootstrap/Container';
import { InvoiceForm } from './components/InvoiceForm';
export default function App() {
	return (
		<div className='app d-lfex flex-column align-items-center justify-content-center w-100'>
			<Container>
				<InvoiceForm />
			</Container>
		</div>
	);
}
